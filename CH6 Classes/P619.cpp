#include "ccc_win.h"
#include "Cannonball.h"

int ccc_win_main()
{
	double alpha = cwin.get_double("Angle?");
	double init_v = cwin.get_double("Initial Velocity");
	cwin.coord(-1, 100, 100, -1);
	Cannonball c1(100.0, 0.0);
	c1.shoot(alpha, init_v);
	return 0;
}