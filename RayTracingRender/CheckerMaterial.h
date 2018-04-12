#pragma once
#include "Material.h"
#include <cmath>
class CheckerMaterial :
	public Material
{
public:
	CheckerMaterial();
	CheckerMaterial(double scale, double reflectiveness, double transparency = 0.0);
	double getReflectiveness();
	double getTransparency();
	void setLightDir(Vector3 &lightDir);
	void setLightColor(Color &lightColor);
	Color sample(Ray ray, Vector3 position, Vector3 normal);
	virtual ~CheckerMaterial();
public:
	double scale;
	double reflectiveness;
	double transparency;
};

