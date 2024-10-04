#include "ccc_win.h"
#include "ccc_time.h"

const double DEG2RAD = 3.14159265358979323 / 180.0;

int ccc_win_main()
{
	int imin = 0, ihrs = 0;
	Point O(0.0, 0.0);
	Time now;
	imin = now.get_minutes();
	ihrs = now.get_hours();
	double min = static_cast<double>(imin);
	double hrs = static_cast<double>(ihrs);

	double minpercentcircle = min / 60.0;
	double hrspercentcircle = (hrs * 60 + min) / (12.0 * 60.0);

	double minangle = minpercentcircle * 360.0;
	double hrsangle = hrspercentcircle * 360.0;

	double minclockangle = 90.0 - minangle;
	double hrsclockangle = 90.0 - hrsangle;

	double minx = 0.0, miny = 0.0, hrsx = 0.0, hrsy = 0.0;

	minx = 0.9 * cos(DEG2RAD * minclockangle);
	miny = 0.9 * sin(DEG2RAD * minclockangle);
	hrsx = 0.6 * cos(DEG2RAD * hrsclockangle);
	hrsy = 0.6 * sin(DEG2RAD * hrsclockangle);

	Line mh(O, Point(minx, miny));
	Line hh(O, Point(hrsx, hrsy));

	cwin.coord(-1.0, 1.0, 1.0, -1.0);
	
	cwin << Circle(O,1) << mh << hh;
	return 0;
}