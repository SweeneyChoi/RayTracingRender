#pragma once
#include "Material.h"
#include <cmath>
class CheckerMaterial :
	public Material
{
public:
	CheckerMaterial();
	CheckerMaterial(double scale);
	CheckerMaterial(double scale, double reflectiveness);
	double getReflectiveness();
	Color sample(Ray ray, Vector3 position, Vector3 normal);
	virtual ~CheckerMaterial();
public:
	double scale;
	double reflectiveness;
};

