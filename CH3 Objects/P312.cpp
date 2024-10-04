#include "ccc_win.h"
#include <string>

using namespace std;

int ccc_win_main()
{
	string name1, name2, name3, name4;
	double m1 = 0.0, m2 = 0.0, m3 = 0.0, m4 = 0.0;

	name1 = cwin.get_string("Name 1: ");
	m1 = cwin.get_double("Longest span: ");
	name2 = cwin.get_string("Name 2: ");
	m2 = cwin.get_double("Longest span: ");
	name3 = cwin.get_string("Name 3: ");
	m3 = cwin.get_double("Longest span: ");
	name4 = cwin.get_string("Name 4: ");
	m4 = cwin.get_double("Longest span: ");

	Point b1bl(0.0, 0.2);
	Point b1tl = b1bl;
	b1tl.move(0.0, 0.8);
	Point b1tr = b1tl;
	b1tr.move(m1, 0.0);
	Line b1l(b1bl, b1tl);
	Line b1r = b1l;
	b1r.move(m1, 0.0);
	Line b1t(b1tl, b1tr);
	Line b1b = b1t;
	b1b.move(0.0, -0.8);

	
	Point b2bl(0.0, 1.2);
	Point b2tl = b2bl;
	b2tl.move(0.0, 0.8);
	Point b2tr = b2tl;
	b2tr.move(m2, 0.0);
	Line b2l(b2bl, b2tl);
	Line b2r = b2l;
	b2r.move(m2, 0.0);
	Line b2t(b2tl, b2tr);
	Line b2b = b2t;
	b2b.move(0.0, -0.8);
	
	Point b3bl(0.0, 2.2);
	Point b3tl = b3bl;
	b3tl.move(0.0, 0.8);
	Point b3tr = b3tl;
	b3tr.move(m3, 0.0);
	Line b3l(b3bl, b3tl);
	Line b3r = b3l;
	b3r.move(m3, 0.0);
	Line b3t(b3tl, b3tr);
	Line b3b = b3t;
	b3b.move(0.0, -0.8);

	Point b4bl(0.0, 3.2);
	Point b4tl = b4bl;
	b4tl.move(0.0, 0.8);
	Point b4tr = b4tl;
	b4tr.move(m4, 0.0);
	Line b4l(b4bl, b4tl);
	Line b4r = b4l;
	b4r.move(m4, 0.0);
	Line b4t(b4tl, b4tr);
	Line b4b = b4t;
	b4b.move(0.0, -0.8);
	
	cwin.coord(0.0, 4.2, 5000.0, 0.0);
	cwin << b1l << b1r << b1t << b1b;
	cwin << b2l << b2r << b2t << b2b;
	cwin << b3l << b3r << b3t << b3b;
	cwin << b4l << b4r << b4t << b4b;
	cwin << Message(b1tl, name1);
	cwin << Message(b2tl, name2);
	cwin << Message(b3tl, name3);
	cwin << Message(b4tl, name4);

	return 0;
}