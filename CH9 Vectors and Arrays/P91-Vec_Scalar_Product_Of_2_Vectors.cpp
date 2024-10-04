/* Exercise P9.1. Write a function

	double scalar_product(vector<double> a, vector<double> b)

that computes the scalar product of two vectors. The scalar product is

	a0b0 + a1b1 + ... + a(n-1)b(n-1).
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	Computes the scalar product of two vectors of floating point numbers
	@param a vector of floating point numbers
	@param b vector of floating point numbers
	return the scalar product of vectors a and b
*/
double scalar_product(const vector<double>& a, const vector<double>& b)
{
	if (a.size() == 0 || b.size() == 0)
		return -1;
	if (a.size() != b.size())
		return -2;
	double scalarProduct = 0;
	for (int i = 0; i < a.size(); i++)
	{
		scalarProduct += a[i] * b[i];
	}
	return scalarProduct;
}
/* Test Harness*/
int main()
{
	//Test for empty vector handling
	vector<double> a(0);
	vector<double> b(10);
	for(int i = 0; i < b.size(); i++)
	{
		b[i] = i;
	}
	double scalarProduct = scalar_product(a, b);
	if (scalarProduct == -1)
		cout << "Empty Vector Test Passed\n";
	else
		cout << "Failed: Empty Vector Test\n";

	//Test for different sized Vector handling
	vector<double> c(9);
	for(int i = 0; i < c.size(); i++)
	{
		c[i] = i;
	}
	vector<double> d(10);
	for(int i = 0; i < d.size(); i++)
	{
		d[i] = i;
	}
	scalarProduct = scalar_product(c, d);
	if (scalarProduct == -2)
		cout << "Different Vector Size Test Passed\n";
	else
		cout << "Failed: Different Vector Size Test\n";
	

	//Test that the function returns the correct value
	vector<double> e(10);
	e[0] = -1.0;
	e[1] = 10.0;
	e[2] = 6.0;
	e[3] = 7.0;
	e[4] = 8.0;
	e[5] = 43.0;
	e[6] = 6.0;
	e[7] = 89.0;
	e[8] = 23.0;
	e[9] = 4.0;

	vector<double> f(10);
	f[0] = 76.0;
	f[1] = 98.0;
	f[2] = 4.0;
	f[3] = 4.5;
	f[4] = 6.8;
	f[5] = -8;
	f[6] = 9;
	f[7] = 4;
	f[8] = 5;
	f[9] = 6;

	scalarProduct = scalar_product(e, f);
	if (scalarProduct == 1218.9)
		cout << "Scalar Product Value Test Passed\n";
	else
		cout << "Failed: Scalar Product Value Test\n";
	return 0;
}