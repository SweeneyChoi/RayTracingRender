#pragma once
#include "Material.h"
#include <cmath>
class PhongMaterial :
	public Material
{
public:
	PhongMaterial();
	PhongMaterial(Color diffuse, Color specular, double shininess);
	PhongMaterial(Color diffuse, Color specular, double shininess, double reflectiveness);
	double getReflectiveness();
	Color sample(Ray ray, Vector3 position, Vector3 normal);
	virtual ~PhongMaterial();
public:
	Color diffuse;
	Color specular;
	double shineness;
	double reflectiveness;
	Vector3 lightDir = Vector3(1.0, 1.0, 1.0).normalize();
	Color lightColor = Color::white();
};


