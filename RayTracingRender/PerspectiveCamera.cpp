#include "PerspectiveCamera.h"
#define PI 3.1415926



PerspectiveCamera::PerspectiveCamera(Vector3 eye, Vector3 front, Vector3 up, double fov) {
	this->eye = eye;
	this->front = front;
	this->refUp = up;
	this->fov = fov;
}

void PerspectiveCamera::initialize() {
	this->right = cross(this->front, this->refUp);
	this->up = cross(this->right, this->front);
	this->fovScale = tan(this->fov*0.5*PI / 180.0) * 2;
}

Ray PerspectiveCamera::generateRay(double x, double y) {
	Vector3 r = this->right*((x - 0.5)*this->fovScale);
	Vector3 u = this->up*((y - 0.5)*this->fovScale);
	return Ray(this->eye, ((this->front + r) + u).normalize());
}


PerspectiveCamera::~PerspectiveCamera()
{
}
