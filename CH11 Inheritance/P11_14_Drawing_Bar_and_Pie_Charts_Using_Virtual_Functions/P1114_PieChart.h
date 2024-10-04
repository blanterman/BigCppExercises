/*	Exercise P11.14. Write a base class Chart that stores a vector of floating
-point values. Implement derived classes, PieChart and BarChart, with a virtual
plot function that can plot the data as a pie chart and as a bar chart.

**To plot the bar and pie charts I used functions from Exercises 9.16 - 9.18

**Yay for reusable code!

Bryson Lanterman 20190503
*/
#include "ccc_win.h"
#include "P1114_Chart.h"

class PieChart : public Chart
{
public:
	/**
		Constructs a PieChart object with empty data vector
	*/
	PieChart();

	/**
		Constructs a PieChart object with given data vector
		@param d vector of data
	*/
	PieChart(std::vector<double> d);

	/**
		plots the data in a bar chart form
	*/
	virtual void plot();
};