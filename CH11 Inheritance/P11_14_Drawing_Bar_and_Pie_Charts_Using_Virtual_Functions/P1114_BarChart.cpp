/*	Exercise P11.14. Write a base class Chart that stores a vector of floating
-point values. Implement derived classes, PieChart and BarChart, with a virtual
plot function that can plot the data as a pie chart and as a bar chart.

**To plot the bar and pie charts I used functions from Exercises 9.16 - 9.18

**Yay for reusable code!

Bryson Lanterman 20190503
*/
#include "ccc_win.h"
#include "P1114_BarChart.h"

/**
	Returns the max value of a given array
	@param data array of floating point numbers
	@return maximum maximum value in the array
*/
double max_val(const vector<double>& data)
{
	double maximum = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if(data[i] > maximum)
		{
			maximum = data[i];
		}
	}
	return maximum;
}

/**
	Returns the min value of a given array
	@param data array of floating point numbers
	@return minimum minimum value in the array
*/
double min_val(const vector<double>& data)
{
	double minimum = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if(data[i] < minimum)
		{
			minimum = data[i];
		}
	}
	return minimum;
}

/**
	draws a bar on the bar chart at the given position with the given value
	@param position the x-position of the bar to be drawn
	@param val the height of the bar to be drawn
*/
void draw_bar(int position, double val)
{
	double leftSidePosition = static_cast<double>(position);
	//Top and bottom lines
	Point p1(leftSidePosition, 0.0);
	Point p2 = p1;
	p2.move(1.0, 0.0);
	Line l1(p1, p2);
	Line l2 = l1;
	l2.move(0.0, val);
	
	//Left and Right side lines
	Line l3(l1.get_start(), l2.get_start());
	Line l4 = l3;
	l4.move(1.0, 0.0);

	//Draw the lines that make up the bar
	cwin << l1 << l2 << l3 << l4;
}

/**
	displays a bar chart of the values in the given array
	@param data vector of positive data
*/
void bar_chart(const vector<double>& data)
{
	// Set the coordinate system min/max values
	double yMaximum = max_val(data) + 1.0;
	double yMinimum = min_val(data) - 1.0;
	double xMaximum = static_cast<double>(data.size()) + 1.0;
	cwin.coord(-1, yMaximum, xMaximum, yMinimum);

	// Draw the bars
	for (int i = 0; i < data.size(); i++)
	{
		draw_bar(i, data[i]);
	}
}

BarChart::BarChart()
	:Chart()
{

}

BarChart::BarChart(std::vector<double> d)
	:Chart(d)
{

}

void BarChart::plot()
{
	bar_chart(Chart::get_data());
}