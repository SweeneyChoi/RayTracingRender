#pragma once
class Vector3 {
public:
	Vector3()=default;
	Vector3(double, double, double);
	double length();
	double sqrLength();
	Vector3 normalize();
	Vector3 negate();
	static Vector3 zero();
	virtual ~Vector3();
	friend Vector3 operator+(const Vector3 &v1, const Vector3 &v2);
	friend Vector3 operator-(const Vector3 &v1, const Vector3 &v2);
	friend Vector3 operator*(const Vector3 &v, double k);
	friend Vector3 operator/(const Vector3 &v, double k);
	friend double Dot(const Vector3 &v1, const Vector3 &v2);
	friend Vector3 cross(const Vector3 &v1, const Vector3 &v2);
public:
	double x, y, z;
};
