#include "ccc_win.h"

const double DEG2RAD = 3.14159265359879323 / 180.0;

int ccc_win_main()
{
	double dp1 = 0.0, dp2 = 0.0, dp3 = 0.0, dp4 = 0.0, sum = 0.0;
	double perc1 = 0.0, perc2 = 0.0, perc3 = 0.0, perc4 = 0.0;
	double deg1 = 0.0, deg2 = 0.0, deg3 = 0.0, deg4 = 0.0;
	double dp1x = 0.0, dp1y = 0.0, dp2x = 0.0, dp2y = 0.0,
		   dp3x = 0.0, dp3y = 0.0, dp4x = 0.0, dp4y = 0.0;

	dp1 = cwin.get_double("first data point: ");
	dp2 = cwin.get_double("second data point: ");
	dp3 = cwin.get_double("third data point: ");
	dp4 = cwin.get_double("fourth data point: ");

	sum = dp1 + dp2 + dp3 + dp4;
	perc1 = dp1 / sum;
	perc2 = dp2 / sum;
	perc3 = dp3 / sum;
	perc4 = dp4 / sum;

	deg1 = perc1 * 360.0;
	deg2 = deg1 + perc2 * 360.0;
	deg3 = deg2 + perc3 * 360.0;
	deg4 = deg3 + perc4 * 360.0;

	dp1x = cos(DEG2RAD * deg1);
	dp1y = sin(DEG2RAD * deg1);
	dp2x = cos(DEG2RAD * deg2);
	dp2y = sin(DEG2RAD * deg2);
	dp3x = cos(DEG2RAD * deg3);
	dp3y = sin(DEG2RAD * deg3);
	dp4x = cos(DEG2RAD * deg4);
	dp4y = sin(DEG2RAD * deg4);

	Point C(0.0, 0.0);

	Line l1(C, Point(dp1x, dp1y));
	Line l2(C, Point(dp2x, dp2y));
	Line l3(C, Point(dp3x, dp3y));
	Line l4(C, Point(dp4x, dp4y));

	cwin.coord(-1.0, 1.0, 1.0, -1.0);
	cwin << Circle(Point(0,0),1) << l1 << l2 << l3 << l4;
	return 0;
}