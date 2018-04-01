#pragma once
#include "Geometry.h"
#include <vector>
class Union :
	public Geometry
{
public:
	Union();
	Union(std::vector<Geometry*> geometries);
	void initialize();
	IntersectResult intersect(Ray ray);
	virtual ~Union();
public:
	std::vector<Geometry*> geometries;
};

