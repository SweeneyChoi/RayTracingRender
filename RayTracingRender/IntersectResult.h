#pragma once
class Geometry;
#include "Vector3.h"
class IntersectResult
{
public:
	IntersectResult();
	static IntersectResult noHit();
	virtual ~IntersectResult();
public:
	Geometry* geometry;
	double distance;
	Vector3 position;
	Vector3 normal;
};

