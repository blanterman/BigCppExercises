#include "stdafx.h"
#include "Car.h"

Car::Car()
{
	fuel_efficiency = 0.0;
	fuel_level = 0.0;
}

Car::Car(double fe)
{
	fuel_efficiency = fe;
	fuel_level = 0.0;
}

void Car::drive(double dist)
{
	fuel_level -= dist / fuel_efficiency;
}

void Car::add_gas(double gal)
{
	fuel_level += gal;
}

double Car::get_gas() const
{
	return fuel_level;
}