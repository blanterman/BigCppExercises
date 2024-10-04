#include "stdafx.h"
#include <string>

using namespace std;

class Country
{
public:
	/**
		Default Constructor
	*/
	Country();

	/**
		Constructor with parameters given
		@param n string country name
		@param pop double population of country
		@param a double area of country in kilometers squared
	*/
	Country(string n, double pop, double a);

	/**
		Returns the name of the country
		@return name string name of the country
	*/
	string get_name() const;

	/**
		Returns the area of the country
		@return area double value of the area of the country (square kilometers)
	*/
	double get_area() const;

	/**
		Returns the population fo the country
		@return population double value of the population of the country
	*/
	double get_population() const;

	/**
		Returns the density of the country
		@return density double population density of the country (people per square kilometer)
	*/
	double get_density() const;

private:
	string name;
	double population;
	double area;
	double density;
};