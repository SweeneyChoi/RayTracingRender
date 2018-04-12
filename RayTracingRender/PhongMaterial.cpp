#include "PhongMaterial.h"
#define max(a,b) ((a>b)?a:b)



PhongMaterial::PhongMaterial()
{
}

PhongMaterial::PhongMaterial(Color diffuse, Color specular, double shineness, double reflectiveness, double transparency) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shineness = shineness;
	this->reflectiveness = reflectiveness;
	this->transparency = transparency;
}

double PhongMaterial::getReflectiveness() {
	return this->reflectiveness;
}

double PhongMaterial::getTransparency() {
	return this->transparency;
}

void PhongMaterial::setLightDir(Vector3 &lightDir) {
	this->lightDir = lightDir;
}

void PhongMaterial::setLightColor(Color &lightColor) {
	this->lightColor = lightColor;
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
