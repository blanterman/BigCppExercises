/*	Exercise P7.13. The value of e^x can be computed as the power series

	e^x = Sum(from n = 1 to infinity)[x^n/factorial(n)]
	    = 1 + x + (x^2/2!) + (x^3/3!) + ...

	Write a function exponential(x) that computes e^x using this formula. Of 
	course, you can't compute an infinite sum. Just keep adding values until 
	an individual summand (term) is less than a certain threshold. At each step
	you need to compute the new term and add it to the total. It would be a 
	poor idea to compute 

		summand = pow(x, n) / factorail(n)

	Instead, update the summand each step:

		summand = summand * x / n;
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

const double EPSILON = 1E-30;

/**
	computes e^x numerically using a power series expansion
	@param x double exponent to which e is to be raised
	return eToX double approximation of the value of e
*/
double exponential(double x)
{
	double eToX = 0;
	double summand = 1;
	int denom = 1;
	while(summand > EPSILON)
	{
		eToX += summand;
		summand *= x / denom;
		denom++;
	}
	return eToX;
}

int main()
{
	cout << "what should we raise e to?: ";
	int exponent;
	cin >> exponent;

	double eToX = exponential(exponent);

	cout << "answer: " << eToX << "\n";
	return 0;
}