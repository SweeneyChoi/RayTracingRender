#include <iostream>
#include <cmath>
#include<vector>
#include <SDL.h>
#include "Vector3.h"
#include "Color.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include "Union.h"
#include "IntersectResult.h"
#include "PerspectiveCamera.h"

#define min(a,b) ((a<b)?a:b)
const static unsigned width = 512;
const static unsigned height = 512;
bool quit = false;

Color rayTrace(Union scene, Ray ray, int maxReflect) {
	IntersectResult result = scene.intersect(ray);
	if (result.geometry) {
		double reflectiveness = result.geometry->material->getReflectiveness();
		Color color = result.geometry->material->sample(ray, result.position, result.normal);
		color = color*(1.0 - reflectiveness);
		if (reflectiveness > 0 && maxReflect > 0) {
			Vector3 r = result.normal*(-2 * Dot(result.normal, ray.direction)) + ray.direction;
			ray = Ray(result.position, r);
			Color reflectColor = rayTrace(scene, ray, maxReflect - 1);
			color = color + (reflectColor*reflectiveness);
		}
		return color;
	}
	else
		return Color::black();
}

void render(SDL_Surface* surface,Union scene, PerspectiveCamera camera, int maxReflect)
{
	scene.initialize();
	camera.initialize();
	SDL_LockSurface(surface);
	auto row = reinterpret_cast<unsigned char*>(surface->pixels);
	for (unsigned y = 0; y < height; ++y)
	{
		double sy = 1.0 - (double)y / height;
		auto p = reinterpret_cast<Uint32*>(row);
		for (unsigned x = 0; x < width; ++x) {
			double sx = (double)x / width;
			Ray ray = camera.generateRay(sx, sy);
			Color color = rayTrace(scene, ray, maxReflect);
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

			Plane* plane = new Plane(Vector3(0.0, 1.0, 0.0), 0.0);
			Sphere* sphere1 = new Sphere(Vector3(-10.0, 10.0, -10.0), 10);
			Sphere* sphere2 = new Sphere(Vector3(10.0, 10.0, -10.0), 10);
			plane->material = new CheckerMaterial(0.1, 0.5);
			sphere1->material = new PhongMaterial(Color::red(), Color::white(), 16, 0.25);
			sphere2->material = new PhongMaterial(Color::blue(), Color::white(), 16, 0.25);

			std::vector<Geometry*> geometries = { plane,sphere1,sphere2 };
			PerspectiveCamera camera(Vector3(0.0, 5.0, 15.0), Vector3(0.0, 0.0, -1.0), Vector3(0.0, 1.0, 0.0), 90.0);
			Union scene(geometries);

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