#include "Color.h"



Color::Color()
{
}

Color::Color(double r, double g, double b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

Color Color::black() {
	return Color(0.0, 0.0, 0.0);
}

Color Color::white() {
	return Color(1.0, 1.0, 1.0);
}

Color Color::red() {
	return Color(1.0, 0.0, 0.0);
}

Color Color::green() {
	return Color(0.0, 1.0, 0.0);
}

Color Color::blue() {
	return Color(0.0, 0.0, 1.0);
}

Color operator+(const Color& c1, const Color& c2) {
	Color c;
	c.r = c1.r + c2.r;
	c.g = c1.g + c2.g;
	c.b = c1.b + c2.b;
	return c;
}

Color operator*(const Color& c, double k) {
	Color color;
	color.r = c.r*k;
	color.g = c.g*k;
	color.b = c.b*k;
	return color;
}

Color operator*(const Color& c1, const Color& c2) {
	Color c;
	c.r = c1.r*c2.r;
	c.g = c1.g*c2.g;
	c.b = c1.b*c2.b;
	return c;
}


Color::~Color()
{
}
