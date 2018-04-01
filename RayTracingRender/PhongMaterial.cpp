#include "PhongMaterial.h"
#define max(a,b) ((a>b)?a:b)



PhongMaterial::PhongMaterial()
{
}

PhongMaterial::PhongMaterial(Color diffuse, Color specular, double shineness) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shineness = shineness;
}

PhongMaterial::PhongMaterial(Color diffuse, Color specular, double shineness, double reflectiveness) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shineness = shineness;
	this->reflectiveness = reflectiveness;
}

double PhongMaterial::getReflectiveness() {
	return this->reflectiveness;
}

Color PhongMaterial::sample(Ray ray, Vector3 position, Vector3 normal) {
	double	NdotL = Dot(normal, lightDir);
	Vector3 H = (lightDir - ray.direction).normalize();
	double NdotH = Dot(normal, H);
	Color diffuseTerm = this->diffuse*max(NdotL, 0);
	Color specularTerm = this->specular*pow(max(NdotH, 0), this->shineness);
	return lightColor*(diffuseTerm + specularTerm);
}


PhongMaterial::~PhongMaterial()
{
}
