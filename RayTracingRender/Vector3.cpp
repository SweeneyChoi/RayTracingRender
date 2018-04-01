#include "Vector3.h"
#include <cmath>


Vector3::Vector3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3(){}

double Vector3::length() {
	return sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
}

double Vector3::sqrLength() {
	return this->x*this->x + this->y*this->y + this->z*this->z;
}

Vector3 Vector3::normalize() {
	double inv = 1.0 / length();
	Vector3 v;
	v.x = this->x*inv;
	v.y = this->y*inv;
	v.z = this->z*inv;
	return v;
}

void Vector3::negate() {
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
}

Vector3 Vector3::zero() {
	return Vector3(0.0, 0.0, 0.0);
}

Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	Vector3 v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return v;
}

Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	Vector3 v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return v;
}

Vector3 operator*(const Vector3& v, double k) {
	Vector3 vector;
	vector.x = v.x*k;
	vector.y = v.y*k;
	vector.z = v.z*k;
	return vector;
}

Vector3 operator/(const Vector3& v, double k) {
	if (fabs(k) < 1e-6)
		k = 1.0;
	double inv = 1 / k;
	Vector3 vector;
	vector.x = v.x * inv;
	vector.y = v.y * inv;
	vector.z = v.z * inv;
	return vector;
}

double Dot(const Vector3& v1, const Vector3& v2) {
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector3 cross(const Vector3& v1, const Vector3& v2) {
	Vector3 v;
	v.x = v1.y*v2.z - v1.z*v2.y;
	v.y = v1.z*v2.x - v1.x*v2.z;
	v.z = v1.x*v2.y - v1.y*v2.x;
	return v;
}