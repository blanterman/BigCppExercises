#include "stdafx.h"

class Car
{
public:
	/**
		Default Constructor
	*/
	Car();

	/**
		Constructor with variables passed
		@param fe double fuel efficiency of the car
	*/
	Car(double fe);

	/**
		Simulates driving the car a given distance
		@param dist double distance traveled
	*/
	void drive(double dist);

	/**
		Adds gas to the cars tank
		@param gal double number of galans to add to fuel level
	*/
	void add_gas(double gal);

	/**
		returns the current fuel level
		@return fuel_level double number of gallons in the tank
	*/
	double get_gas() const;

private:
	double fuel_efficiency;
	double fuel_level;
};