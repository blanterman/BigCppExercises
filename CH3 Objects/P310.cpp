#include "ccc_win.h"

int ccc_win_main()
{
	// H
	Point h1(-3.5, 1.0);
	Point h2 = h1;
	h2.move(0.0, -1.0);
	Point h3 = h2;
	h3.move(0.0, -1.0);
	Point h4 = h2;
	h4.move(1.0, 0.0);
	Point h5 = h4, h6 = h4;
	h5.move(0.0, 1.0);
	h6.move(0.0, -1.0);

	cwin << Line(h1, h3) << Line(h2, h4) << Line(h5, h6);

	// E
	Point h7(-2.0, 1.0);
	Point h8 = h7;
	h8.move(0.0, -1.0);
	Point h9 = h8;
	h9.move(0.0, -1.0);
	Point h10 = h8;
	h10.move(1.0, 0.0);
	Point h11 = h10, h12 = h10;
	h11.move(0.0, 1.0);
	h12.move(0.0, -1.0);

	cwin << Line(h7, h9) << Line(h8, h10) << Line(h9, h12) << Line(h7, h11);

	// L
	Point h13(-0.5, 1.0);
	Point h14 = h13;
	h14.move(0.0, -2.0);
	Point h15 = h14;
	h15.move(1.0, 0.0);

	cwin << Line(h13, h14) << Line(h14, h15);

	// L
	Point h16(1.0, 1.0);
	Point h17 = h16;
	h17.move(0.0, -2.0);
	Point h18 = h17;
	h18.move(1.0, 0.0);

	cwin << Line(h16, h17) << Line(h17, h18);

	// O
	Circle o(Point(3.0, 0.0), 1);
	cwin << o;

	return 0;
}