#pragma once
class Color
{
public:
	Color();
	Color(double, double, double);
	static Color black();
	static Color white();
	static Color red();
	static Color green();
	static Color blue();
	virtual ~Color();
	friend Color operator+(const Color& c1, const Color& c2);
	friend Color operator*(const Color& c, double k);
	friend Color operator*(const Color& c1, const Color& c2);

public:
	double r;
	double g;
	double b;
};

