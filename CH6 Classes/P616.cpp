#include "ccc_win.h"
#include "Street.h"

int ccc_win_main()
{
	Point h1_loc = cwin.get_mouse("Select location of first house on street");
	cwin << h1_loc; // User feedback
	Point h2_loc = cwin.get_mouse("Select location of last house on street");
	cwin << h2_loc; // User feedback
	double num_houses = cwin.get_double("How many houses will be on the street?");

	House first(1.0, h1_loc);
	House last(num_houses, h2_loc);

	Street s(first, last, num_houses);
	s.plot();

	return 0;
}