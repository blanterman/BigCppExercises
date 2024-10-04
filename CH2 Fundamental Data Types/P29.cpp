// P29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	const int DLR = 100;
	const int QTR = 25;
	const int DIM = 10;
	const int NIC = 5;

	double in_amt_due = 0, in_amt_rcvd = 0, dbl_change = 0;
	int amt_due = 0, amt_rcvd = 0, change = 0,
		dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;

	cout << "What is the amount due?\n";
	cin >> in_amt_due;
	cout << "What was the amount received?\n";
	cin >> in_amt_rcvd;

	//double type value of change due
	dbl_change = in_amt_rcvd - in_amt_due;

	//use int values for all calculations
	amt_due = static_cast<int>(in_amt_due * 100);
	amt_rcvd = static_cast<int>(in_amt_rcvd * 100);
	change = amt_rcvd - amt_due;

	//how many dollars are due back
	dollars = change / DLR;
	change = change % DLR;

	//how many quarters are due back
	quarters = change / QTR;
	change = change % QTR;

	//how many dimes are due back
	dimes = change / DIM;
	change = change % DIM;

	//how may nickels are due back
	nickels = change / NIC;
	change = change % NIC;

	//only pennies are left
	pennies = change;

	//print out change due
    cout << "The ammount of change due is: " << dbl_change << "\n"
		 << "Give them back:\n"
		 << dollars << " dollar bills,\n"
		 << quarters << " quarters,\n"
		 << dimes << " dimes,\n"
		 << nickels << " nickels, and\n"
		 << pennies << " pennies.\n";

	return 0;
}

