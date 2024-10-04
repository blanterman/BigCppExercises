/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429

Exercise P11.12. Use the preceding exercise as the basis for a drawing program.
Users can place various shapes onto the screen by first clicking on a shape 
icon and then clicking on the desired screen location.

Bryson Lanterman 20190501
*/

#include "ccc_win.h"
#include "P1112_Shape.h"
#include "P1112_Rectangle.h"
#include "P1112_Square.h"
#include "P1112_Triangle.h"

/*
	Draw the board
*/
void drawBoard()
{
	// Construct lines for box of boxes
	cwin.coord(0.0, 0.0, 125.0, 125.0);
	Point p1(5.0, 5.0);
	Point p2 = p1;
	p2.move(15.0, 0.0);
	Point p3 = p1;
	p3.move(0.0, 75.0);
	Line l1(p1, p2);
	Line l2(p1, p3);
	Line l3 = l1;
	Line l4 = l1;
	Line l5 = l1;
	Line l6 = l1;
	Line l7 = l1;
	l3.move(0.0, 15.0);
	l4.move(0.0, 30.0);
	l5.move(0.0, 45.0);
	l6.move(0.0, 60.0);
	l7.move(0.0, 75.0);
	Line l8 = l2;
	l8.move(15.0, 0.0);

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

	// Construct quit message
	Message m1(Point(8.0, 55.0), "CLEAR");

	// Construct quit message
	Message m2(Point(10.0, 70.0), "QUIT");

	// Plot all shapes
	cwin << l1 << l2 << l3 << l4 << l5 << l6 << l7 << l8		//box of boxes
		<< rt << rb << rl << rr									//rectangle
		<< st << sb << sl << sr									//square
		<< tb << tl << tr										//triangle
		<< m1													//message clear
		<< m2;												//message quit
}
bool selRec(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (5.0 <= click.get_y() && click.get_y() < 20.0))
	{
		return true;
	}
	return false;
}
bool selSquare(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (20.0 <= click.get_y() && click.get_y() < 35.0))
	{
		return true;
	}
	return false;
}
bool selTri(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (35.0 <= click.get_y() && click.get_y() <= 50.0))
	{
		return true;
	}
	return false;
}
bool onBoard(Point click)
{
	if ((25.0 <= click.get_x() && click.get_x() <= 125.0) && (5.0 <= click.get_y() && click.get_y() <= 125.0))
	{
		return true;
	}
	return false;
}
bool checkQuit(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (65.0 <= click.get_y() && click.get_y() <= 80.0))
	{
		return true;
	}
	return false;
}
bool checkClear(Point click)
{
	if ((5.0 <= click.get_x() && click.get_x() <= 20.0) && (50.0 <= click.get_y() && click.get_y() <= 65.0))
	{
		return true;
	}
	return false;
}

int ccc_win_main()
{
	bool tri = false;
	bool rec = false;
	bool sqr = false;
	drawBoard();
	Shape* selShape = NULL;
	bool cont = true;
	while (cont)
	{
		Point click = cwin.get_mouse("");
		if (onBoard(click))
		{
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
			if(selShape != NULL)
			{
				selShape->plot();
			}
		}
		if (selRec(click))
		{
			tri = false;
			rec = true;
			sqr = false;
		}
		if (selSquare(click))
		{
			tri = false;
			rec = false;
			sqr = true;
		}
		if (selTri(click))
		{
			tri = true;
			rec = false;
			sqr = false;
		}
		if (checkQuit(click))
		{
			cont = false;
		}
		if (checkClear(click))
		{
			cwin.clear();
			drawBoard();
		}
		
	}
	return 0;
}