#include "stdafx.h"
#include "SodaCan.h"

double const PI = 3.14159265358979323;

SodaCan::SodaCan()
{
	height = 0.0;
	radius = 0.0;
}

SodaCan::SodaCan(double h, double r)
{
	height = h;
	radius = r;
}

double SodaCan::get_surface_area() const
{
	return 2.0 * PI * radius * radius + 2.0 * PI * radius * height;
}

double SodaCan::get_volume() const
{
	return PI * radius * radius * height;
}