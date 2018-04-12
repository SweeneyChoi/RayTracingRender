#include "CheckerMaterial.h"



CheckerMaterial::CheckerMaterial()
{
}

CheckerMaterial::CheckerMaterial(double scale, double reflectiveness, double transparency) {
	this->scale = scale;
	this->reflectiveness = reflectiveness;
	this->transparency = transparency;
}

double CheckerMaterial::getReflectiveness() {
	return this->reflectiveness;
}

double CheckerMaterial::getTransparency() {
	return this->transparency;
}

void CheckerMaterial::setLightDir(Vector3 &lightDir) {
	this->lightDir = lightDir;
}
void CheckerMaterial::setLightColor(Color &lightColor) {
	this->lightColor = lightColor;
}

Color CheckerMaterial::sample(Ray ray, Vector3 position, Vector3 normal) {
	return abs((int)(floor(position.x*this->scale) + floor(position.z*this->scale)) % 2) < 1 ? Color::black() : Color::white();
}

CheckerMaterial::~CheckerMaterial()
{
}
