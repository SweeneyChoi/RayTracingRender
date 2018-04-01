#include "CheckerMaterial.h"



CheckerMaterial::CheckerMaterial()
{
}

CheckerMaterial::CheckerMaterial(double scale) {
	this->scale = scale;
}

CheckerMaterial::CheckerMaterial(double scale, double reflectiveness) {
	this->scale = scale;
	this->reflectiveness = reflectiveness;
}

double CheckerMaterial::getReflectiveness() {
	return this->reflectiveness;
}

Color CheckerMaterial::sample(Ray ray, Vector3 position, Vector3 normal) {
	return abs((int)(floor(position.x*this->scale) + floor(position.z*this->scale)) % 2) < 1 ? Color::black() : Color::white();
}


CheckerMaterial::~CheckerMaterial()
{
}
