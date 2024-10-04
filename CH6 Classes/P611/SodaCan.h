#pragma once
#include "stdafx.h"

class SodaCan
{
public:
	/**
		Default Constructor
	*/
	SodaCan();

	/**
		Constructor with given height and radius
		@param h double height of can
		@param r double radius of can
	*/
	SodaCan(double h, double r);

	/**
		Returns the surface area of can
		@return SA double surface area of can
	*/
	double get_surface_area() const;

	/**
		Returns the volume of the can
		@return Vol double volume of can
	*/
	double get_volume() const;
private:
	double height;
	double radius;
};