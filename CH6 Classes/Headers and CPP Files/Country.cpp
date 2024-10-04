#include "stdafx.h"
#include "Country.h"

Country::Country()
{
	population = 0.0;
	area = 0.0;
	density = 0.0;
}

Country::Country(string n, double pop, double a)
{
	name = n;
	population = pop;
	area = a;
	density = pop / a;
}

string Country::get_name() const
{
	return name;
}

double Country::get_area() const
{
	return area;
}

double Country:: get_population() const
{
	return population;
}

double Country::get_density() const
{
	return density;
}