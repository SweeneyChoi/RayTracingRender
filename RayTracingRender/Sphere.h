#pragma once
#include "Geometry.h"
#include "Vector3.h"
#include "PhongMaterial.h"
#include <cmath>
class Sphere :
	public Geometry
{
public:
	Sphere()=default;
	Sphere(Vector3 center, double radius);
	void initialize();
	IntersectResult intersect(Ray& ray);
	virtual ~Sphere();
public:
	Vector3 center;
	double radius;
	double sqrRadius;
};

