#include "Light.h"



Light::Light()
{
}

Light::Light(const Vector3 &position, const Color &color):m_position(position),m_color(color) {}

Vector3 Light::getPosition() {
	return m_position;
}

Color Light::getColor() {
	return m_color;
}

Light::~Light()
{
}
