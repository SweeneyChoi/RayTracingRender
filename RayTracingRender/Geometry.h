#pragma once
#include "Ray.h"
#include "IntersectResult.h"
#include "Material.h"
class Geometry
{
public:
	Geometry();
	virtual void initialize() = 0;
	virtual IntersectResult intersect(Ray ray) = 0;
	virtual ~Geometry();
public:
	Material* material;
};

