/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429

Exercise P11.12. Use the preceding exercise as the basis for a drawing program.
Users can place various shapes onto the screen by first clicking on a shape 
icon and then clicking on the desired screen location.

Bryson Lanterman 20190501

Exercise P11.13. Extend the program of the preceding exercise by adding another
shape type: CircleShape. (You cannot call it Circle, because there already is a
Circle class in the graphics library.) Explain what changes you needed to make 
in the program to implement this extension. How do virtual functions help in 
making the program easily extensible?

Bryson Lanterman 20190501
*/

#include "ccc_win.h"
#include "P1113_Shape.h"
#include "P1113_Rectangle.h"
#include "P1113_Square.h"
#include "P1113_Triangle.h"
#include "P1113_CircleShape.h"

/**
	Draw the board
*/
void drawBoard()
{
	// Set the coordinate System
	cwin.coord(0.0, 0.0, 125.0, 125.0);

	// Construct lines for box of boxes
	Point p1(5.0, 5.0);
	Point p2 = p1;
	p2.move(15.0, 0.0);
	Point p3 = p1;
	p3.move(0.0, 90.0);
	Line l1(p1, p2);
	Line l2(p1, p3);
	Line l3 = l1;
	Line l4 = l1;
	Line l5 = l1;
	Line l6 = l1;
	Line l7 = l1;
	Line l8 = l1;
	l3.move(0.0, 15.0);
	l4.move(0.0, 30.0);
	l5.move(0.0, 45.0);
	l6.move(0.0, 60.0);
	l7.move(0.0, 75.0);
	l8.move(0.0, 90.0);
	Line l9 = l2;
	l9.move(15.0, 0.0);

	// Construct lines for rectangle shape in box
	Point r1(7.0, 10.0);
	Point r2 = r1;
	r2.move(11.0, 0.0);
	Point r3 = r1;
	r3.move(0.0, 5.0);
	Line rt(r1, r2);
	Line rb = rt;
	rb.move(0.0, 5.0);
	Line rl(r1, r3);
	Line rr = rl;
	rr.move(11.0, 0.0);

	// Construct lines for square shape in box
	Point s1(7.0, 22.0);
	Point s2 = s1;
	s2.move(11.0, 0.0);
	Point s3 = s1;
	s3.move(0.0, 11.0);
	Line st(s1, s2);
	Line sb = st;
	sb.move(0.0, 11.0);
	Line sl(s1, s3);
	Line sr = sl;
	sr.move(11.0, 0.0);

	// construct lines for triangle shape in box
	Point t1(6.0, 49.0);
	Point t2 = t1;
	t2.move(13.0, 0.0);
	Point t3 = t1;
	t3.move(6.5, -sqrt(3.0) * 13 / 2);
	Line tb(t1, t2);
	Line tl(t1, t3);
	Line tr(t2, t3);

	// construct circle in box
	Circle c1(Point(12.5, 57.5), 6.5);

	// Construct quit message
	Message m1(Point(8.0, 70.0), "CLEAR");

	// Construct quit message
	Message m2(Point(10.0, 85.0), "QUIT");

	// Plot all shapes
	cwin << l1 << l2 << l3 << l4 << l5 << l6 << l7 << l8 << l9	//box of boxes
		<< rt << rb << rl << rr									//rectangle
		<< st << sb << sl << sr									//square
		<< tb << tl << tr										//triangle
		<< c1													//circle
		<< m1													//message clear
		<< m2;													//message quit
}

/**
	Checks to see if the clicked mouse location is in the rectangle select box
	@param click Point location of the mouse click
	@return true if the location is in the rectangle select box, false otherwise
*/
bool selRec(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (5.0 <= click.get_y() && click.get_y() < 20.0))
	{
		return true;
	}
	return false;
}

/**
	Checks to see if the clicked mouse location is in the square select box
	@param click Point location of the mouse click
	@return true if the location is in the square select box, false otherwise
*/
bool selSquare(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (20.0 <= click.get_y() && click.get_y() < 35.0))
	{
		return true;
	}
	return false;
}

/**
	Checks to see if the clicked mouse location is in the triangle select box
	@param click Point location of the mouse click
	@return true if the location is in the triangle select box, false otherwise
*/
bool selTri(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (35.0 <= click.get_y() && click.get_y() <= 50.0))
	{
		return true;
	}
	return false;
}

/**
	Checks to see if the clicked mouse location is in the circle select box
	@param click Point location of the mouse click
	@return true if the location is in the circle select box, false otherwise
*/
bool selCir(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (50.0 < click.get_y() && click.get_y() <= 65.0))
	{
		return true;
	}
	return false;
}

/**
	Checks to see if the clicked mouse location is in the drawing area of the board
	@param click Point location of the mouse click
	@retrun true if the location is in the drawing area of the board
*/
bool onBoard(Point click)
{
	if ((25.0 <= click.get_x() && click.get_x() <= 125.0) && (5.0 <= click.get_y() && click.get_y() <= 125.0))
	{
		return true;
	}
	return false;
}

/**
	Checks to see if the clicked mouse location is in the QUIT select box
	@param click Point location of the mouse click
	@return true if the location is in the QUIT select box, false otherwise
*/
bool checkQuit(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (80.0 <= click.get_y() && click.get_y() <= 95.0))
	{
		return true;
	}
	return false;
}

/**
	Checks to see if the clicked mouse location is in the CLEAR select box
	@param click Point location of the mouse click
	@return true if the location is in the CLEAR select box, false otherwise
*/
bool checkClear(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (65.0 <= click.get_y() && click.get_y() <= 80.0))
	{
		return true;
	}
	return false;
}

int ccc_win_main()
{
	// Set shape selected flag vars
	bool tri = false;
	bool rec = false;
	bool sqr = false;
	bool cir = false;

	// draw the board with all boxes
	drawBoard();

	// Initialize shape pointer
	Shape* selShape = NULL;

	// Initialize loop flag
	bool cont = true;

	// Main program loop for drawing shapes
	while (cont)
	{
		// Get the location of the mouse.
		Point click = cwin.get_mouse("");

		// If the click was in the drawing area then decide what to do
		if (onBoard(click))
		{
			// If a shape selected flag has been set then get the pointer to a shape object of default size at the current click location
			if (tri)
			{
				selShape = new Triangle(click, 10.0);
			}
			if (rec)
			{
				selShape = new Rectangle(click, 10.0, 20.0);
			}
			if (sqr)
			{
				selShape = new Square(click, 10.0);
			}
			if (cir)
			{
				selShape = new CircleShape(click, 5.0);
			}

			// Plot the shape object if there was a selection. This will be skipped over until a shape is selected
			if(selShape != NULL)
			{
				selShape->plot();
			}
		}

		// Check to see if the click is trying to select a shape to draw then set the corresponding flag while resetting all other flags
		if (selRec(click))
		{
			tri = false;
			rec = true;
			sqr = false;
			cir = false;
		}
		if (selSquare(click))
		{
			tri = false;
			rec = false;
			sqr = true;
			cir = false;
		}
		if (selTri(click))
		{
			tri = true;
			rec = false;
			sqr = false;
			cir = false;
		}
		if (selCir(click))
		{
			tri = false;
			rec = false;
			sqr = false;
			cir = true;
		}

		// Check to see if the click is in the quit box and set the loop flag if necessary
		if (checkQuit(click))
		{
			cont = false;
		}

		// Check to see if the click is in the clear box. If it is, clear the screen and redraw the board
		if (checkClear(click))
		{
			cwin.clear();
			drawBoard();
		}
		
	}
	return 0;
}