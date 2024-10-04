/*	Exercise P11.14. Write a base class Chart that stores a vector of floating
-point values. Implement derived classes, PieChart and BarChart, with a virtual
plot function that can plot the data as a pie chart and as a bar chart.

**To plot the bar and pie charts I used functions from Exercises 9.16 - 9.18

**Yay for reusable code!

Bryson Lanterman 20190503
*/
#include "ccc_win.h"
#include "P1114_PieChart.h"

const double PI = 3.14159265358979;

PieChart::PieChart()
	:Chart()
{

}

PieChart::PieChart(std::vector<double> d)
	:Chart(d)
{

}

void PieChart::plot()
{
	double total = 0;
	for (int i = 0; i < Chart::get_data().size(); i++)
	{
		total += Chart::get_data()[i];
	}

	double cumulativeTotal = 0;
	Point origin(0.0, 0.0);
	for (int i = 0; i < Chart::get_data().size(); i++)
	{
		double fractionOfCircle = 0;
		double radians = 0;
		double x = 0;
		double y = 0;
		cumulativeTotal += Chart::get_data()[i];
		fractionOfCircle = cumulativeTotal / total;
		radians = fractionOfCircle * (2 * PI);
		x = cos(radians);
		y = sin(radians);
		Point p1(x, y);
		Line l1(origin, p1);
		Circle unitCircle(origin, 1.0);
		cwin.coord(-1.1, 1.1, 1.1, -1.1);
		cwin << unitCircle << l1;
	}
}