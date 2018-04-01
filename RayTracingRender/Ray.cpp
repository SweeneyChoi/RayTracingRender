#include "Ray.h"


Ray::Ray(Vector3 origin, Vector3 direction) {
	this->origin = origin;
	this->direction = direction;
}

Vector3 Ray::getPoint(double t) {
	return this->origin + direction*t;
}


Ray::~Ray()
{
}
