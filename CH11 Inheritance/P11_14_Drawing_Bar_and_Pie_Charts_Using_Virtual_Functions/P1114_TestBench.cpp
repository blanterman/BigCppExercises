/*	Exercise P11.14. Write a base class Chart that stores a vector of floating
-point values. Implement derived classes, PieChart and BarChart, with a virtual
plot function that can plot the data as a pie chart and as a bar chart.

**To plot the bar and pie charts I used functions from Exercises 9.16 - 9.18

**Yay for reusable code!

Bryson Lanterman 20190503
*/
#include "ccc_win.h"
#include "P1114_PieChart.h"
#include "P1114_BarChart.h"
#include <vector>

int ccc_win_main()
{
	std::vector<double> b(10);
	b[0] = 1;
	b[1] = 2;
	b[2] = 1;
	b[3] = 2;
	b[4] = 1;
	b[5] = 2;
	b[6] = 1;
	b[7] = 2;
	b[8] = 1;
	b[9] = 2;

	BarChart p1(b);
	//PieChart p1(b);
	p1.plot();



	return 0;
}