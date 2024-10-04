// P57.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const double PI = 3.14159265358979323;

/**
	Computes the volume of a sphere
	@param r radius of the sphere
	@return volume
*/
double sphere_volume(double r)
{
	return (4.0 / 3.0) * PI * r * r * r;
}

/**
	Computes the surface area of a sphere
	@param r radius of the sphere
	@return surface area
*/
double sphere_surface(double r)
{
	return 4.0 * PI * r * r;
}

/**
	Computes the volume of a cylinder
	@param r radius of the cylinder
	@param h height of the cylinder
	@return volume
*/
double cylinder_volume(double r, double h)
{
	return PI * r * r * h;
}

/**
	Computes the surface area of a cylinder
	@param r radius of the cylinder
	@param h height of the cylinder
	@return surface area
*/
double cylinder_surface(double r, double h)
{
	return 2.0 * PI * r * r + 2.0 * PI * r * h;
}

/**
	Computes the volume of a cone
	@param r radius of the base of the cone
	@param h height of the cone
	@return volume
*/
double cone_volume(double r, double h)
{
	return (1.0 / 3.0) * PI * r * r * h;
}

/**
	Computes the surface area of a cone
	@param r radius of the base of the cone
	@param h height of the cone
	@return surface area
*/
double cone_surface(double r, double h)
{
	return PI * r * r + PI * r * sqrt(h * h + r * r);
}

int main()
{
	double radius = 0, height = 0, sphereV = 0, sphereSA = 0, cylinderV = 0,
		   cylinderSA = 0, coneV = 0, coneSA = 0;
	
	cout << "Please provide a radius and a height: ";
	
	cin >> radius >> height;
	
	sphereV = sphere_volume(radius);
	sphereSA = sphere_surface(radius);
	cylinderV = cylinder_volume(radius, height);
	cylinderSA = cylinder_surface(radius, height);
	coneV = cone_volume(radius, height);
	coneSA = cone_surface(radius, height);

	cout << "Radius: " << radius << endl
		 << "Height: " << height << "\n\n"
		 << "Volume of Sphere: " << sphereV << endl
		 << "Surface Area of Sphere: " << sphereSA << endl
		 << "Volume of Cylinder: " << cylinderV << endl
		 << "Surface Area of Cylinder: " << cylinderSA << endl
		 << "Volume of Cone: " << coneV << endl
		 << "Surface Area of Cone: " << coneSA << endl;
	return 0;
}

