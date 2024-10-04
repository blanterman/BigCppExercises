#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const double RATE1 = 0.15;
	const double RATE2 = 0.28;
	const double RATE3 = 0.31;

	const double SINGLE_LEVEL1 = 21450.00;
	const double SINGLE_LEVEL2 = 51900.00;

	const double MARRIED_LEVEL1 = 35800.00;
	const double MARRIED_LEVEL2 = 86500.00;

	double income = 0;
	double tax = 0;

	string marital_status;

	cout << "Please enter your income: ";
	cin >> income;

	cout << "Please enter s for single, m for married: ";
	cin >> marital_status;

	//This is confusing code and bad practice, but I felt like a baller writing it.
	double cutoff15 = marital_status == "s" ? SINGLE_LEVEL1 : MARRIED_LEVEL1;
	double cutoff28 = marital_status == "s" ? SINGLE_LEVEL2 : MARRIED_LEVEL2;

	if(income <= cutoff15)
	{
		tax = RATE1 * income;
	}
	else if(income <= cutoff28)
	{
		tax = RATE1 * cutoff15 + RATE2 * (income - cutoff15);
	}
	else
	{
		tax = RATE1 * cutoff15 + RATE2 * (cutoff28 - cutoff15) + RATE3 * (income - cutoff28);
	}

	cout << "The tax is $" << tax << "\n";

	return 0;
}