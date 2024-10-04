/*	Write a procedure

void pie_chart(vector<double> data)

that displays a pie chart of the values in data. You may assume that all values
in data are positive.

Bryson Lanterman 20180823
*/

#include "ccc_win.h"
#include <vector>

using namespace std;

const double PI = 3.14159265358979323;

/**
	Displays a pie chart of values in a vector. Assumes all values are 
	positive.
	@param data a vector of data
*/
void pie_chart(vector<double> data)
{
	double total = 0;
	for (int i = 0; i < data.size(); i++)
	{
		total += data[i];
	}

	double cumulativeTotal = 0;
	Point origin(0.0, 0.0);
	for (int i = 0; i < data.size(); i++)
	{
		double fractionOfCircle = 0;
		double radians = 0;
		double x = 0;
		double y = 0;
		cumulativeTotal += data[i];
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

int ccc_win_main()
{
	vector<double> data(10);
	data[0] = 1.0;
	data[1] = 2.0;
	data[2] = 5.0;
	data[3] = 7.0;
	data[4] = 2.0;
	data[5] = 7.0;
	data[6] = 9.0;
	data[7] = 4.0;
	data[8] = 54.0;
	data[9] = 2.0;
	pie_chart(data);
	return 0;
}