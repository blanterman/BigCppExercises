/*	Exercise P11.7. Implement a base class Vehicle and derived classes Car and
Truck. A vehicle has a position on the screen. Write virtual functions draw
that draw cars and trucks as are shown on page 431 of the book. Then populate a
vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of
them.

Bryson Lanterman 20190228
*/

#include "P117_Truck.h"

Truck::Truck()
	:Vehicle()
{

}

Truck::Truck(Point loc)
	:Vehicle(loc)
{

}

void Truck::draw()
{
	Point loc = Vehicle::get_loc();
	// Create the left part of the truck
	// Left and right lines
	Point p1 = loc;
	Point p2 = loc;
	p1.move(0.0, -1.5);
	p2.move(0.0, -5.0);
	Line l1(p1, p2);
	Line l2 = l1;
	l2.move(2.9, 0.0);
	// Top and bottom lines
	Point p3 = p1;
	Point p4 = p1;
	p4.move(2.9, 0.0);
	Line l3(p3, p4);
	Line l4 = l3;
	l4.move(0.0, -3.5);

	//Create the right part of the truck
	// Left and right lines
	Point p5 = loc;
	Point p6 = loc;
	p5.move(3.0, 0.0);
	p6.move(3.0, -5.0);
	Line l5(p5, p6);
	Line l6 = l5;
	l6.move(10.0, 0.0);
	// Top and bottom lines
	Point p7 = p5;
	Point p8 = p5;
	p8.move(10.0, 0.0);
	Line l7(p7, p8);
	Line l8 = l7;
	l8.move(0.0, -5.0);

	//Create wheels
	Point p9(loc.get_x() + 1.0, loc.get_y() - 5.5);
	Circle c1(p9, 0.5);
	Circle c2 = c1;
	c2.move(2.5, 0.0);
	Circle c3 = c2;
	c3.move(1.1, 0.0);
	Circle c4 = c3;
	c4.move(6.8, 0.0);
	Circle c5 = c4;
	c5.move(1.1, 0.0);

	// Draw lines and circles
	cwin << l1 << l2 << l3 << l4
		<< l5 << l6 << l7 << l8
		<< c1 << c2 << c3 << c4 << c5;
}