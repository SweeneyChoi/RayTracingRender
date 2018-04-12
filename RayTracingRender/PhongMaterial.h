#pragma once
#include "Material.h"
#include "Light.h"
#include <cmath>
#include <vector>
class PhongMaterial :
	public Material
{
public:
	PhongMaterial();
	PhongMaterial(Color diffuse, Color specular, double shininess, double reflectiveness = 0.0, double transparency = 0.0);
	double getReflectiveness();
	double getTransparency();
	Color sample(Ray ray, Vector3 position, Vector3 normal);
	void setLightDir(Vector3 &lightDir);
	void setLightColor(Color &lightColor);
	virtual ~PhongMaterial();
public:
	Color diffuse;
	Color specular;
	double shineness;
	double reflectiveness;
	double transparency;
	Vector3 lightDir;
	Color lightColor;
};


