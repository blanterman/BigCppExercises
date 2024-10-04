#include "ccc_win.h"
#include "Triangle.h"

//This is also P610

int ccc_win_main()
{
	Point c1(-5.0, 5.0);
	Point c2(7.0, 5.0);
	Point c3(6.0, -6.0);

	Triangle t1(c1, c2, c3);
	t1.plot();
	
	double p1 = t1.get_perimeter();
	cwin << Message(c1, p1);

	double a1 = t1.get_area();
	cwin << Message(c2, a1);


	return 0;
}