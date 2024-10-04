/*	Exercise P11.7. Implement a base class Vehicle and derived classes Car and 
Truck. A vehicle has a position on the screen. Write virtual functions draw 
that draw cars and trucks as are shown on page 431 of the book. Then populate a
vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of 
them.

Bryson Lanterman 20190228
*/

#include "ccc_win.h"
#include "P117_Car.h"
#include "P117_Truck.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

/*
	Returns a double between low and high
*/
double randVal(double low, double high)
{
	return low + (high - low) * rand() * (1.0 / RAND_MAX);
}

int ccc_win_main()
{
	// Set the coordinates of the output plane
	cwin.coord(-50.0, 50.0, 63.0, -56.0);
	// Set variables
	int numVehicles = 50;
	int type = 0;
	double x = 0;
	double y = 0;
	
	// Seed the rand() this is for the function above too.
	srand(time(NULL));
	
	// Create a vector to hold all the Veclcle pointers 
	// Pointers are used for polymorphism
	vector<Vehicle*> vehicles(numVehicles);

	// Populate the vector with a random number of cars and trucks that add up to numVehicles
	for (int i = 0; i < numVehicles; i++)
	{
		// Get the type of vehicle variable
		type = (rand() % 2);

		// Get the location of the vehicle
		Point loc(randVal(-50.0, 50.0), randVal(-50.0, 50.0));
		
		// If type is 0 then put a car pointer in the vector
		if (type == 0)
		{
			vehicles[i] = new Car(loc);
		}
		// If type is 1 then put a truck pointer in the vector
		else
		{
			vehicles[i] = new Truck(loc);
		}
	}

	// Iterate through the vector and use the virtual functions to draw the different vehicles
	for (int i = 0; i < vehicles.size(); i++)
	{
		vehicles[i]->draw();
	}
	
	return 0;
}