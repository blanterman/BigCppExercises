/*	Exercise P10.6. Write a function that returns a pointer to the maximum 
value of an array of floating-point data:

double* maximum(double a[], int a_size)

If a_size is 0, return NULL.

Bryson Lanterman 20181019
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	Returns the pointer to the maximum value of an array of floatint-point data
	@param a array of floating point data
	@param a_size size of the array of floating point data
	@return p pointer to maximum value
*/
double* maximum(double a[], int a_size)
{
	if (a_size == 0)
	{
		return NULL;
	}

	double maximum = *a;
	double* p = a;

	for (int i = 1; i < a_size; i++)
	{
		if (*(a + i) > maximum)
		{
			maximum = *(a + i);
			p = (a + i);
		}
	}
	return p;
}

int main()
{
	// Test Harness
	double arr[] = { 1, 22, 3, 4, 5, 16, 7, 8, 152, 10 }; // max is 22
	double* mx = maximum(arr, 10);

	if (mx != NULL)
	{
		cout << *mx << "\n";
	}
	else
		cout << "Empty Array\n";
	return 0;
}