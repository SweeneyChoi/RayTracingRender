#include "Plane.h"



Plane::Plane()
{
}

Plane::Plane(Vector3 normal, double d) {
	this->normal = normal;
	this->d = d;
}

void Plane::initialize() {
	this->position = normal*this->d;	
}

IntersectResult Plane::intersect(Ray ray) {
	double a = Dot(ray.direction, this->normal);
	if (a >= 0) {
		return IntersectResult::noHit();
	}

	double b = Dot(this->normal, (ray.origin - this->position));
	IntersectResult result = IntersectResult();
	result.geometry = this;
	result.distance = -b / a;
	result.position = ray.getPoint(result.distance);
	result.normal = this->normal;
	return result;
}


Plane::~Plane()
{
}
