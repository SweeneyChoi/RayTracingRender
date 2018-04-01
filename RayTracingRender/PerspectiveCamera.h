#pragma once
#include "Vector3.h"
#include "Ray.h"
#include<cmath>
class PerspectiveCamera
{
public:
	PerspectiveCamera()=default;
	PerspectiveCamera(Vector3 eye, Vector3 front, Vector3 up, double fov);
	void initialize();
	Ray generateRay(double x, double y);
	virtual ~PerspectiveCamera();
public:
	Vector3 eye;
	Vector3 front;
	Vector3 up;
	Vector3 refUp;
	Vector3 right;
	double fov;
	double fovScale;
};

