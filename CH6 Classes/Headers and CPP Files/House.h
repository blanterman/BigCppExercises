#include "ccc_win.h"

class House
{
public:
	/**
		Default constructor
	*/
	House();

	/**
		Constructor with the given parameters
		@param hn double house number
		@param loc Point location of bottom left of house on grid
	*/
	House(double hn, Point loc);

	/**
		Returns the location of the house
		@return location point location of the bottom left corner of the house
	*/
	Point get_location() const;

	/**
		Plots the house at its location with its number under it
		@param corr double corrective factor for the size of the house
		       if there are too many houses to fit, the houses get smaller.
	*/
	void plot(double corr) const;
private:
	double house_number;
	Point location;
};