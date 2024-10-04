/*	Exercise P11.14. Write a base class Chart that stores a vector of floating
-point values. Implement derived classes, PieChart and BarChart, with a virtual
plot function that can plot the data as a pie chart and as a bar chart.

**To plot the bar and pie charts I used functions from Exercises 9.16 - 9.18

**Yay for reusable code!

Bryson Lanterman 20190503
*/

#pragma once

#include "ccc_win.h"
#include <vector>

class Chart
{
public:
	/**
		Constructs a Chart object with an empty vector of data
	*/
	Chart();
	/**
		Constructs a Chart object with given vector of data
		@param d vector of data
	*/
	Chart(std::vector<double> d);
	/**
		Returns a pointer to the data vector
	*/
	std::vector<double> get_data() const;
	/**
		Graph the data
	*/
	virtual void plot();
private:
	std::vector<double> data;
};