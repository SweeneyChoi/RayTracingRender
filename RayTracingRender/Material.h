#pragma once
#include "Vector3.h"
#include "Color.h"
#include "Ray.h"
class Material
{
public:
	Material();
	virtual Color sample(Ray ray, Vector3 position, Vector3 normal) = 0;
	virtual double getReflectiveness() = 0;
	virtual ~Material();
public:
};

