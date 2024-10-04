/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429
*/

#include "ccc_win.h"
#include "P1111_Rectangle.h"
#include "P1111_Square.h"
#include "P1111_Triangle.h"
#include <cstdlib> // random
#include <ctime>
#include <vector>
#include <iomanip>
#include <sstream>

const double MAX_WIDTH = 20.0;
const double MAX_HEIGHT = 20.0;
const double MIN_WIDTH = 1.0;
const double MIN_HEIGHT = 1.0;

/**
	Converts a double to a string
	@param val double to convert to a string
	@return string representation of val
*/
std::string dtostr(double val)
{
	ostringstream streamObj;
	streamObj << fixed; // to avoid scientific notation
	streamObj << val;
	return streamObj.str();
}

/*
	Returns a double between two given values.
	@param low lower bound
	@param high upper bound
	@return random value between low and high
*/
double randBet(double low, double high)
{
	return low + (high - low) * rand() * (1.0 / RAND_MAX);
}

/*
	Populates the given vector of Shapes with the given number of randomly located and randomly sized rectangles
	@param vShapes pointer to vector of shapes
	@param numRecs the integer number of shapes to populate
*/
void popRecs(vector<Shape*>& vShapes, int numRecs, double locXMin, double locXMax, double locYMin, double locYMax)
{
	double x = 0;
	double y = 0;
	double w = 0;
	double h = 0;
	Point loc;
	for (int i = 0; i < numRecs; i++)
	{
		w = randBet(MIN_WIDTH, MAX_WIDTH);
		h = randBet(MIN_HEIGHT, MAX_HEIGHT);
		x = randBet(locXMin, locXMax);
		y = randBet(locYMin, locYMax);
		loc = Point(x, y);
		vShapes.push_back(new Rectangle(loc, h, w));
	}
}

/*
	Populates the given vector of Shapes with the given number of randomly located and randomly sized squares
	@param vShapes pointer to vector of shapes
	@param numSquares the integer number of shapes to populate
*/
void popSquares(vector<Shape*>& vShapes, int numSquares, double locXMin, double locXMax, double locYMin, double locYMax)
{
	double x = 0;
	double y = 0;
	double w = 0;
	Point loc;
	for (int i = 0; i < numSquares; i++)
	{
		w = randBet(MIN_WIDTH, MAX_WIDTH);
		x = randBet(locXMin, locXMax);
		y = randBet(locYMin, locYMax);
		loc = Point(x, y);
		vShapes.push_back(new Square(loc, w));
	}
}

/*
	Populates the given vector of Shapes with the given number of randomly located and randomly sized triangles
	@param vShapes pointer to vector of shapes
	@param numTris the integer number of shapes to populate
*/
void popTris(vector<Shape*>& vShapes, int numTris, double locXMin, double locXMax, double locYMin, double locYMax)
{
	double x = 0;
	double y = 0;
	double b = 0;
	Point loc;
	for (int i = 0; i < numTris; i++)
	{
		b = randBet(MIN_WIDTH, MAX_WIDTH);
		x = randBet(locXMin, locXMax);
		y = randBet(locYMin, locYMax);
		loc = Point(x, y);
		vShapes.push_back(new Triangle(loc, b));
	}
}

int ccc_win_main()
{
	// Shape quantity variables
	int numSquares = 10;
	int numRecs = 10;
	int numTris = 10;
	// Coordinate plane variables
	double planeXMin = -50.0;
	double planeXMax = 50.0;
	double planeYMin = -50;
	double planeYMax = 50;
	// Shape location variables adjusted so that no shape will go off grid
	double locXMin = -50;
	double locXMax = 50 - MAX_WIDTH;
	double locYMin = -50;
	double locYMax = 50 - MAX_HEIGHT;
	// Display variables
	double totalArea = 0.0;
	std::string message;
	Point msgLoc(planeXMin, planeYMin + 3.0);

	// Create a vector of shape pointers
	vector<Shape*> shapes;

	// Seed the random generator for all functions.
	srand(time(NULL));

	// Populate the shapes vector with pointers to rectangles and squares
	popRecs(shapes, numRecs, locXMin, locXMax, locYMin, locYMax);
	popSquares(shapes, numSquares, locXMin, locXMax, locYMin, locYMax);
	popTris(shapes, numTris, locXMin, locXMax, locYMin, locYMax);

	// Set the coordinates of the output plane
	cwin.coord(planeXMin, planeYMax, planeXMax, planeYMin);

	// plot all shapes, calculate total area, display area
	for (int i = 0; i < shapes.size(); i++)
	{
		totalArea += shapes[i]->get_area();
		shapes[i]->plot();
	}
	message = "Total Area: " + dtostr(totalArea);
	Message m1(msgLoc, message);
	cwin << m1;

	return 0;
}