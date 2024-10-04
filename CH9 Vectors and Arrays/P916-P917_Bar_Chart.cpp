/*	Exercise P9.16. Write a procedure

void bar_chart(vector<double> data)

that displays a bar chart of the values in data. You may assume that all values
in data are positive. Hint: you must figure out the maximum of the values in 
data. Set the cooridinate system so that the x-rannge equals the number of bars
and the y-range goes from 0 to the maximum.

Bryson Lanterman 20180813
*/

/*	Exercise P9.17. Improve the bar_chart procedure of the preceding exercise 
to work correctly wien data contains negative values.

Bryson Lanterman 20180813
*/

#include "ccc_win.h"
#include <vector>

using namespace std;

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
******* Added for P9.17 **********
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
	double yMinimum = min_val(data) - 1.0;  // Added for P9.17
	double xMaximum = static_cast<double>(data.size()) + 1.0;
	cwin.coord(-1, yMaximum, xMaximum, yMinimum); // Changed for P9.17

	// Draw the bars
	for (int i = 0; i < data.size(); i++)
	{
		draw_bar(i, data[i]);
	}
}


int ccc_win_main()
{
	
	vector<double> data(20);
	//P916
	data[0] = 3;
	data[1] = 1;
	data[2] = 4;
	data[3] = 1;
	data[4] = 5;
	data[5] = 9;
	data[6] = 2;
	data[7] = 6;
	data[8] = 5;
	data[9] = 3;

	//P917
	data[10] = -3;
	data[11] = -1;
	data[12] = -4;
	data[13] = -1;
	data[14] = -5;
	data[15] = -9;
	data[16] = -2;
	data[17] = -6;
	data[18] = -5;
	data[19] = -3;

	bar_chart(data);
	return 0;
}
