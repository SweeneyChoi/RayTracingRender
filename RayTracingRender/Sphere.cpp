#include "Sphere.h"




Sphere::Sphere(Vector3 center, double radius) {
	this->center = center;
	this->radius = radius;
}

void Sphere::initialize() {
	this->sqrRadius = this->radius*this->radius;
}

IntersectResult Sphere::intersect(Ray ray) {
	Vector3 v = ray.origin - this->center;
	double a0 = v.sqrLength() - this->sqrRadius;
	double DdotV = Dot(ray.direction, v);

	if (DdotV <= 0) {
		double discr = DdotV*DdotV - a0;
		if (discr >= 0) {
			IntersectResult result;
			result.geometry = this;
			result.distance = -DdotV - sqrt(discr);
			result.position = ray.getPoint(result.distance);
			result.normal = (result.position - this->center).normalize();
			return result;
		}
	}
	return IntersectResult::noHit();
}


Sphere::~Sphere()
{
	delete material;	
}
