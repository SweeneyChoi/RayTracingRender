#pragma once
#include "Geometry.h"
#include "CheckerMaterial.h"
class Plane :
	public Geometry
{
public:
	Plane();
	Plane(Vector3 normal, double d);
	void initialize();
	IntersectResult intersect(Ray ray);
	virtual ~Plane();
public:
	Vector3 normal;
	double d;
	Vector3 position;
};

