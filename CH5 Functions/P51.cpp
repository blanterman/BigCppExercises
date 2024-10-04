// P51.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>

using namespace std;

/*
	Computes the value of an investment with compound interest.
	@param initial_balance the initial value of the investment
	@param p the interest rate in percent; must be >= 0
	@param n the number of periods the investment is held; must be >= 0
	@return The balance after n periods
*/
double future_value(double initial_balance, double p, int n)
{
	assert(p>=0);
	assert(n>=0);

	return initial_balance * pow(1 + p / 100, n);
}

int main()
{
	double initial_balance = 0, p = 0, post_10 = 0, post_20 = 0, post_30 = 0;

	cout << "Provide initial balance and interest rate: ";
	cin >> initial_balance >> p;

	post_10 = future_value(initial_balance, p, 10);
	post_20 = future_value(initial_balance, p, 20);
	post_30 = future_value(initial_balance, p, 30);

	cout << "Your balance after 10 cycles will be: " << post_10 << ".\n"
		 << "Your balance after 20 cycles will be: " << post_20 << ".\n"
		 << "Your balance after 30 cycles will be: " << post_30 << ".\n";

	return 0;
}

