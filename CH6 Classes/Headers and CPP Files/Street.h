#include "ccc_win.h"
#include "House.h"

class Street
{
public:
	/**
		Default Constructor
	*/
	Street();

	/**
		Constructor with parameters passed
	*/
	Street(House first, House last, double n_houses);

	/**
		Plots the street with the appropriate number of houses equally spaced
	*/
	void plot() const;
private:
	House first_house;
	House last_house;
	double num_houses;
};
