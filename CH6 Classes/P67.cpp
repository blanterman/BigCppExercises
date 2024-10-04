//This is also P68

#include "Rectangle.h"

int ccc_win_main()
{
	Rectangle r1(Point(0.0, 0.0), Point(2.0, 1.0));
	r1.plot();
	Rectangle r2 = r1;
	r2.move(1.0, 1.0);
	r2.plot();
	Rectangle r3(Point(-10.0, 10.0), Point(-1.0, 5.0));
	r3.plot();
	
	cwin << Message(Point(0.0, 1.0), r1.get_area())
		 << Message(Point(1.0, 2.0), r2.get_area())
		 << Message(Point(-10.0, 10.0), r3.get_area());
	
	cwin << Message(Point(1.0, 1.0), r1.get_perimeter())
		 << Message(Point(2.0, 2.0), r2.get_perimeter())
		 << Message(Point(-9.0, 10.0), r3.get_perimeter());
	
	return 0;
}