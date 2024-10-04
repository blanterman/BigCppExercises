/** 
Exercise P13.2 - Write a bumper car game with the following rules. Bumper 
cars are located in grid points (x,y), where x and y are integers between -10
and 10. A bumper car starts moving in a random direction, either left, right,
up, or down. If it reaches the boundary of its track (that is, x or y is 10 or
-10), then it reverses direction. if it is about to bump into another bumper 
car, it reverses direction. Model a track with two bomper cars. Make each of 
them move 100 times, alternating between the two cars. Display the movement on
the graphics screen. Use at leat two classes in your program. There shuld be no
global variables.

Bryson Lanterman 8/21/24 - 9/13/24
Notes:
8/21/24 - Finished BumperCar Class. Still need Track class and Game class.
More notes are in C++ notebook on Page 45.
9/13/24 - Finished the first version of the game. Put 10 cars instead of two.
Need to change the collision checker. Right now they collide if they overlap,
but I want them to change direction before that.
*/
#include "ccc_win.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

/**
	Seeds the random function
*/
void random_seed()
{
	std::srand(std::time(NULL));
}

/**
	Returns a random integer between and including 2 integers
	@param a lower limit
	@param b upper limit
	@return a pseudo random integer between a and b
*/
int random_int(int a, int b)
{
	return a + std::rand() % (b - a + 1);
}

/**
	A bumpercar that has a location, size, and can draw itself
*/
class BumperCar
{
public:
	/**
		Constructs a bumper car with a location, width, and height
		@param loc Point top lefthand point of the 1x1 square bumpercar
		@param w double width of the car
		@param h double height of the car
	*/
	BumperCar(Point loc, double w, double h, std::vector<int> dir);
	/**
		Sets the location of the bumper car
		@param loc Point location of the top lefthand point of the bumper car
	*/
	void set_location(Point loc);
	/**
		Sets the length and width of the bumper car
		@param w double width of the bumper car
		@param h double height of the bumper car
	*/
	void set_width_and_height(double w, double h);
	/**
		Sets the direction of the bumper car the first index in x dir and the second index is y dir
		[-1,0] -> left, [1,0] -> right, [0, -1] -> down, [0, 1] -> up.
		@param dir vector representing direction [-1,0] left, [1,0] right, [0, -1] down, [0, 1] up
	*/
	void set_direction(std::vector<int> dir);
	/**
		Returns the location of the top lefthand point of the bumper car
		@return loc Point of the top lefthand point of the bumper car
	*/
	Point get_location() const;
	/**
		Returns the length and width of the bumper car in a vector
		@return sizeLW vector doubles describing the size of the car as length and width 
	*/
	std::vector<double> get_width_and_height() const;
	/**
		Returns the direction of the car
		@return direction vector 
	*/
	std::vector<int> get_direction() const;
	/**
		Draws the bumper car using horstmann graphics ccc library
	*/
	void draw();
private:
	Point location;
	double width, height;
	std::vector<int> direction;
};

BumperCar::BumperCar(Point loc, double w, double h, std::vector<int> dir)
{
	location = loc;
	width = w;
	height = h;
	direction = dir;
}

void BumperCar::set_location(Point loc)
{
	location = loc;
}

void BumperCar::set_width_and_height(double w, double h)
{
	width = w;
	height = h;
}

void BumperCar::set_direction(std::vector<int> dir)
{
	direction = dir;
}

Point BumperCar::get_location() const
{
	return location;
}

std::vector<double> BumperCar::get_width_and_height() const
{
	std::vector<double> widthAndHeight(2);
	widthAndHeight[0] = width;
	widthAndHeight[1] = height;
	return widthAndHeight;
}

std::vector<int> BumperCar::get_direction() const
{
	return direction;
}

void BumperCar::draw()
{
	// Define corners of the car based on location (top left is location).
	Point top_right = Point(location.get_x() + width, location.get_y());
	Point bottom_left = Point(location.get_x(), location.get_y() - height);
	Point bottom_right = Point(location.get_x() + width, location.get_y() - height);
	// Define the lines of the car using corner points
	Line l_top = Line(location, top_right);
	Line l_bottom = Line(bottom_left, bottom_right);
	Line l_left = Line(location, bottom_left);
	Line l_right = Line(top_right, bottom_right);
	// Draw the car
	cwin << l_top << l_bottom << l_left << l_right;
}

/**
	A bumper car track that has cars and can check for collisions with cars and walls and can draw itself
*/
class Track
{
public:
	/**
		Default constructor
	*/
	Track();
	/**
		Sets the cars of the track
	*/
	void set_cars(std::vector<BumperCar> bc);
	/**
		Checks for collisions and reports which cars have collided
		@return collisions vector of boolean values indicating collisions with cars or walls.
	*/
	std::vector<bool> check_collisions();
	/**
		Returns the cars of the track
		@return cars vector of BumperCars
	*/
	std::vector<BumperCar> get_cars() const;
	/**
		Draws all the cars on the track
	*/
	void draw_track();
private:
	std::vector<BumperCar> cars;
};

Track::Track()
{

}

void Track::set_cars(std::vector<BumperCar> bc)
{
	cars = bc;
}

std::vector<bool> Track::check_collisions()
{
	int numCars = cars.size();					// get number of cars in a variable
	std::vector<bool> collisions(numCars);		// initialize vector that will be returned
	for (int i = 0; i < numCars; i++)			// Go through all the cars
	{
		for (int j = i + 1; j < numCars; j++)	// Compare the location of the current car to all the cars it hasn't been compared to yet
		{
			if ((cars[i].get_location().get_x() == cars[j].get_location().get_x()) && (cars[i].get_location().get_y() == cars[j].get_location().get_y()))	// same location means colliding
			{
				collisions[i] = true;			// Set the collision value of both cars equal to true
				collisions[j] = true;
			}
		}
		if (cars[i].get_location().get_x() + cars[i].get_width_and_height()[0] == 10 ||		// Hitting the right wall
			cars[i].get_location().get_x() == -10 ||										// Hitting the left wall
			cars[i].get_location().get_y() == 10 ||											// Hitting the top wall
			cars[i].get_location().get_y() - cars[i].get_width_and_height()[1] == -10)		// Hitting the bottom wall
		{
			collisions[i] = true;				// Set collision value to true
		}
	}
	return collisions;
}

std::vector<BumperCar> Track::get_cars() const
{
	return cars;
}

void Track::draw_track()
{
	cwin.clear();							// First clear the track
	for (int i = 0; i < cars.size(); i++)	// Go through the cars and draw them on track.
	{
		cars[i].draw();
	}
}

/**
	Bumper car game that starts 10 cars in random positions, moves them in 
	random directions, and reverses them if they collide with eachother or 
	the walls of the track.
*/
class BCGame
{
public:
	/**
		Default constructor, a track with 10 cars in ranom positions
	*/
	BCGame();
	/**
		Advances the cars forward one space. If there was a collision changes the direction
	*/
	void advance_cars();

private:
	Track BCTrack;
};

BCGame::BCGame()
{
	random_seed();									// Seed the random function only at beginning of game
	// Initialize variables for cars and track
	double carWidth = 1;							// Width of car
	double carHeight = 1;							// Height of car
	std::vector<int> direction(2);					// Variable to store the direction
	std::vector<BumperCar> cars;					// Variable to store the cars for the track
	for (int i = 0; i < 10; i++)					
	{
		int directionNum = random_int(1, 4);		// Determing a random direction for the cars to start travelling.
		if (directionNum == 1)
		{
			direction[0] = -1;
			direction[1] = 0;
		}
		if (directionNum == 2)
		{
			direction[0] = 1;
			direction[1] = 0;
		}
		if (directionNum == 3)
		{
			direction[0] = 0;
			direction[1] = -1;
		}
		if (directionNum == 4)
		{
			direction[0] = 0;
			direction[1] = 1;
		}
		// Determine a random location for the car to start at
		int x = random_int(-9, 9 - carWidth);		
		int y = random_int(-9 + carHeight, 9);
		Point location = Point(x, y);
		// Create the car object and populate the vector with the new car.
		BumperCar bumperCar = BumperCar(location, carWidth, carHeight, direction);
		cars.push_back(bumperCar);
	}
	BCTrack.set_cars(cars);				// Add all the cars to the track
	BCTrack.draw_track();				// Draw the track
}

void BCGame::advance_cars()
{
	std::vector<BumperCar> cars = BCTrack.get_cars();				// Get the current cars
	std::vector<bool> collisions = BCTrack.check_collisions();		// Find out if there are any collisions
	for (int i = 0; i < cars.size(); i++)							// Reverse the direction of the cars if there is a collision
	{
		std::vector<int> dir = cars[i].get_direction();				// Get the current direction of the current car
		std::vector<int> newDir = dir;								// Set the new direction to the old direction so there will be no change if no collision
		if (collisions[i])											// If there is  a collision
		{
			newDir[0] = -1 * dir[0];								// Change the x or y direction (no effect if 0)
			newDir[1] = -1 * dir[1];	
			cars[i].set_direction(newDir);							// Apply the new direction
		}
		cars[i].set_location(Point(cars[i].get_location().get_x() + newDir[0], cars[i].get_location().get_y() + newDir[1]));	// Set the car's new location based on the new direction
	}
	BCTrack.set_cars(cars);						// Update the cars with their new directions and locations
	BCTrack.draw_track();						// Draw the updated positions of the cars.
}

int ccc_win_main()
{
	BCGame game = BCGame();						// Start the game and draw the cars
	for (int i = 0; i < 100; i++)				// Move the cars 100 times, waiting 0.1 seconds between moves.
	{
		game.advance_cars();
		// Waiting for 1 second
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	return 0;
}