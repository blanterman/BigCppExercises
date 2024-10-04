/*	Exercise P10.5. Write a function that computes the average value of an 
array of floating point data:

double average(double* a, int a_size)

In the function, use a pointer variable, and not an integer index, to traverse
the array elements.

Bryson Lanterman 20181019
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	computes the average value of an array of floating point data
	@param a array of floating point data
	@param a_size number of valid values in the array
	@return average average value
*/
double average(double* a, int a_size)
{
	if (a_size == 0)
	{
		return 0.0;
	}
	double sum = *a;
	const double* p = a + 1;
	int count = a_size - 1;
	while (count > 0)
	{
		sum += *p;
		p++;
		count--;
	}
	return sum / a_size;
}

int main()
{
	// Test Harness
	double arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Average is 5.5
	double av = average(arr, 10);

	cout << av << "\n";
	return 0;
}