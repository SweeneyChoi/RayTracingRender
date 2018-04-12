#pragma once
#include "Vector3.h"
#include "Color.h"
#include "Ray.h"

class Material
{
public:
	Material();
	virtual Color sample(Ray ray, Vector3 position, Vector3 normal) = 0;
	virtual double getReflectiveness() = 0;
	virtual double getTransparency() = 0;
	virtual void setLightDir(Vector3 &lightDir) = 0;
	virtual void setLightColor(Color &lightColor) = 0;
	virtual ~Material();
public:
	Vector3 lightDir;
	Color lightColor;
};

