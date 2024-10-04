/*	Exercise P11.7. Implement a base class Vehicle and derived classes Car and
Truck. A vehicle has a position on the screen. Write virtual functions draw
that draw cars and trucks as are shown on page 431 of the book. Then populate a
vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of
them.

Bryson Lanterman 20190228
*/

#include "P117_Car.h"

Car::Car()
	:Vehicle()
{

}

Car::Car(Point loc)
	:Vehicle(loc)
{

}

void Car::draw()
{
	Point loc = Vehicle::get_loc();
	// Create the upper part of the car
	// Left and right lines
	Point p1 = loc;
	Point p2 = loc;
	p1.move(2.0, 0.0);
	p2.move(2.0, -1.0);
	Line l1(p1, p2);
	Line l2 = l1;
	l2.move(3.0, 0.0);
	// Top and bottom lines
	Point p3 = p1;
	Point p4 = p1;
	p4.move(3.0, 0.0);
	Line l3(p3, p4);
	Line l4 = l3;
	l4.move(0.0, -1.0);

	//Create the bottom part of the car
	// Left and right lines
	Point p5 = loc;
	Point p6 = loc;
	p5.move(0.0, -1.0);
	p6.move(0.0, -2.5);
	Line l5(p5, p6);
	Line l6 = l5;
	l6.move(7.0, 0.0);
	// Top and bottom lines
	Point p7 = p5;
	Point p8 = p5;
	p8.move(7.0, 0.0);
	Line l7(p7, p8);
	Line l8 = l7;
	l8.move(0.0, -1.5);
	
	//Create wheels
	Point p9(loc.get_x() + 1.5, loc.get_y() - 3);
	Circle c1(p9, 0.5);
	Circle c2 = c1;
	c2.move(4.0, 0.0);

	// Draw lines and circles
	cwin << l1 << l2 << l3 << l4
		<< l5 << l6 << l7 << l8
		<< c1 << c2;
}