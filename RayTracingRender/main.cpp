#include <iostream>
#include <cmath>
#include<vector>
#include <SDL.h>
#include "Vector3.h"
#include "Color.h"
#include "Ray.h"
#include "Light.h"
#include "Sphere.h"
#include "Plane.h"
#include "Union.h"
#include "IntersectResult.h"
#include "PerspectiveCamera.h"

#define min(a,b) ((a<b)?a:b)
const static unsigned width = 512;
const static unsigned height = 512;
bool quit = false;

struct Scene {
	Union object;
	std::vector<Light*> lights;
};

Color rayTrace(Scene scene, Ray ray, int depth) {
	IntersectResult result = scene.object.intersect(ray);
	Color surfaceColor(0.0, 0.0, 0.0);
	if (result.geometry) {
		double reflectiveness = result.geometry->material->getReflectiveness();
		double transparency = result.geometry->material->getTransparency();
		for (Light* light : scene.lights) {
			Vector3 lightDir = (light->getPosition() - result.position).normalize();
			Ray shadowRay(result.position + result.normal*1e-5, lightDir);
			IntersectResult shadowResult = scene.object.intersect(shadowRay);
			if (!shadowResult.geometry) {
				result.geometry->material->setLightDir(lightDir);
				result.geometry->material->setLightColor(light->getColor());
				surfaceColor = surfaceColor + result.geometry->material->sample(ray, result.position, result.normal);
				surfaceColor = surfaceColor*(1.0 - reflectiveness);
			}
		}

		bool inside = false;
		if (Dot(result.normal, ray.direction) > 0) {
			inside = true;
			result.normal = result.normal*(-1);
		}
		double facingratio = Dot(ray.direction*(-1), result.normal);
		double fresneleffect = reflectiveness + (1.0 - reflectiveness)*pow((1.0 - facingratio), 5);
		if (reflectiveness > 0 && depth > 0) {
			Vector3 reflectDir = result.normal*(-2 * Dot(result.normal, ray.direction)) + ray.direction;
			reflectDir.normalize();
			Ray reflectRay(result.position + result.normal*1e-5, reflectDir);
			Color reflectColor = rayTrace(scene, reflectRay, depth - 1);
			surfaceColor = surfaceColor + reflectColor*fresneleffect;
		}
		if (transparency > 0 && depth > 0) {
			double ior = 1.5;
			double eta = (inside) ? ior : 1.0 / ior;
			double cosi = Dot(ray.direction*(-1), result.normal);
			Vector3 CE = result.normal*cosi;
			Vector3 GF = (ray.direction + CE)*eta;
			double sin_t2_2 = (1.0 - cosi*cosi)*eta*eta;
			if (sin_t2_2 < 1.0) {
				Vector3 GC = result.normal*sqrt(1.0 - sin_t2_2);
				Vector3 refractDir = GF - GC;
				refractDir.normalize();
				Ray refractRay(result.position - result.normal * 1e-4, refractDir);
				Color refractColor = rayTrace(scene, refractRay, depth - 1);
				surfaceColor = surfaceColor + refractColor*(1.0 - fresneleffect)*transparency;
			}
		}
		return surfaceColor;
	}
	else
		return Color::black();
}

void render(SDL_Surface* surface,Scene scene, PerspectiveCamera camera, int depth)
{
	scene.object.initialize();
	camera.initialize();
	SDL_LockSurface(surface);
	auto row = reinterpret_cast<unsigned char*>(surface->pixels);
	for (unsigned y = 0; y < height; ++y)
	{
		double sy = 1.0 - (double)y / height;
		auto p = reinterpret_cast<Uint32*>(row);
		for (unsigned x = 0; x < width; ++x) {
			double sx = (double)x / width;
			Ray ray;
			camera.generateRay(sx, sy, ray);
			Color color = rayTrace(scene, ray, depth);
			color.r = color.r <= 1.0 ? color.r : 1.0;
			color.g = color.g <= 1.0 ? color.g : 1.0;
			color.b = color.b <= 1.0 ? color.b : 1.0;
			*p++ = SDL_MapRGB(surface->format, color.r * 255, color.g * 255, color.b * 255);
		}
		row += surface->pitch;
	}
	SDL_UnlockSurface(surface);
}
int main(int argc, char *argv[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	SDL_Event e;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("Ray Tracing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screen = SDL_GetWindowSurface(window);
			atexit(SDL_Quit);

			std::vector<Geometry*> geometries;
			std::vector<Light*> lights;

			Plane* plane = new Plane(Vector3(0.0, 1.0, 0.0), 0.0);
			Sphere* sphere1 = new Sphere(Vector3(4.0, 10.0, -16.0), 10.0);
			Sphere* sphere2 = new Sphere(Vector3(-4.0, 4.0, 0.0), 4.0);
			Sphere* sphere3 = new Sphere(Vector3(8.0, 4.0, -2.0), 4.0);
			plane->material = new CheckerMaterial(0.1, 0.5, 0.0);
			sphere1->material = new PhongMaterial(Color(1.0,0.3,0.8), Color::white(), 16, 0.25);
			sphere2->material = new PhongMaterial(Color(0.3, 0.8, 1.0), Color::white(), 16, 0.2, 1.0);
			sphere3->material = new PhongMaterial(Color(0.3, 1.0, 0.8), Color::white(), 16, 0.2, 1.0);

			geometries.push_back(plane);
			geometries.push_back(sphere1);
			geometries.push_back(sphere2);
			geometries.push_back(sphere3);

			PerspectiveCamera camera(Vector3(0.0, 4.0, 15.0), Vector3(0.0, 0.0, -1.0), Vector3(0.0, 1.0, 0.0), 90.0);
			Union objects(geometries);

			Light* light1 = new Light(Vector3(-10.0, 20.0, 30.0), Color(1.0, 1.0, 1.0));
			lights.push_back(light1);

			Scene scene;
			scene.object = objects;
			scene.lights = lights;


			while (!quit) {
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				render(screen, scene, camera, 3);
				SDL_UpdateWindowSurface(window);
			}
		}
	}


	return 0;
}