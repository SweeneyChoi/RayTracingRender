#pragma once
#include "Vector3.h"
#include "Color.h"

class Light
{
public:
	Light();
	Light(const Vector3 &position, const Color &color);
	Vector3 getPosition();
	Color getColor();
	virtual ~Light();
protected:
	Vector3 m_position;
	Color m_color;
};

