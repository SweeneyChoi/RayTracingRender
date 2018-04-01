#pragma once
#include "Vector3.h"
class Ray
{
public:
	Ray()=default;
	Ray(Vector3 origin, Vector3 direction);
	Vector3 getPoint(double t);
	virtual ~Ray();
public:
	Vector3 origin;
	Vector3 direction;
};

