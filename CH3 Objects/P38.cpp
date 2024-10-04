#include "ccc_win.h"

int ccc_win_main()
{
	Circle face(Point(0, 0), 3.0);
	
	Circle leye(Point(-1.25, 1.0), 0.25);
	Circle reye = leye;
	reye.move(2.5, 0);

	Line mouth(Point(-1.5, -1.0), Point(1.5, -1.0));

	cwin << face << leye << reye << mouth;

	return 0;
}