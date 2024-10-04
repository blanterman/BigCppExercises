#include "ccc_win.h"
#include "Street.h" //#include "House.h" is in here

const double PERCENT_GAP = 0.90;

Street::Street()
{
	first_house = House(1, Point(0.0, 0.0));
	last_house = House(2, Point(0.0, 0.0));
	num_houses = 2.0;
}

Street::Street(House first, House last, double n_houses)
{
	first_house = first;
	last_house = last;
	num_houses = n_houses;
}

void Street::plot() const
{
	
	double dx = (last_house.get_location().get_x()-first_house.get_location().get_x())/(num_houses - 1.0);
	double dy = (last_house.get_location().get_y()-first_house.get_location().get_y())/(num_houses - 1.0);
	double new_x = first_house.get_location().get_x();
	double new_y = first_house.get_location().get_y();
	double corr = PERCENT_GAP * dx; // corrective size factor is a percentage of the space available for each house in the x-direction
	
	//Plot the first and last house
	first_house.plot(corr);
	last_house.plot(corr);

	//Loop to add each house between the first and last house on the fly
	for(int i = 0; i < num_houses - 2; i++)
	{
		new_x += dx;
		new_y += dy;

		House new_house(i + 2, Point(new_x, new_y));
		new_house.plot(corr);
	}
}