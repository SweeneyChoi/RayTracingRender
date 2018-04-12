#include "Sphere.h"




Sphere::Sphere(Vector3 center, double radius) {
	this->center = center;
	this->radius = radius;
}

void Sphere::initialize() {
	this->sqrRadius = this->radius*this->radius;
}

IntersectResult Sphere::intersect(Ray& ray) {
	Vector3 l = this->center - ray.origin;
	//double a0 = v.sqrLength() - this->sqrRadius;
	double DdotL = Dot(ray.direction, l);
	if (DdotL < 0) {
		return IntersectResult::noHit();
	}

	double b2 = Dot(l, l) - DdotL*DdotL;
	double r2 = this->radius*this->radius;

	if (b2 > r2) {
		return IntersectResult::noHit();
	}

	double c = sqrt(r2 - b2);
	IntersectResult result;
	result.geometry = this;
	double near = DdotL - c;
	double far = DdotL + c;
	result.distance = (near < 0) ? far : near;
	result.position = ray.getPoint(result.distance);
	result.normal = (result.position - this->center).normalize();
	return result;
}


Sphere::~Sphere()
{
	delete material;	
}
