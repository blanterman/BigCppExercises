// P220.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	// this is the given Code with errors
	int total;
	cout << "please enter a number: ";
	double x1;
	cin >> x1;
	cout << "total = " << total << "\n";
	total = total + x1;
	cout << "total = " << total << "\n";
	cout << "Please enter a number: ";
	double x2;
	cin >> x2;
	total = total + x2;
	cout << "total = " << total << "\n";
	total = total / 2;
	cout << "The average is " << total << "\n";
	return 0;
	*/

	/*
	//this is my fixed code with the trace messages in
	int total = 0;
	double x1 = 0, x2 = 0, average = 0;

	cout << "total = " << total << "\n";
	cout << "please enter a number: ";
	cin >> x1;

	total = total + x1;
	cout << "total = " << total << "\n";
	
	cout << "Please enter a number: ";
	cin >> x2;
	
	total = total + x2;
	cout << "total = " << total << "\n";
	
	average = total / 2.0;
	cout << "The average is " << average << "\n";
	return 0;
	*/

	//this is my fixed code without the trace messages in
	int total = 0;
	double x1 = 0, x2 = 0, average = 0;
		
	cout << "please enter a number: ";
	cin >> x1;
	total = total + x1;

	cout << "Please enter a number: ";
	cin >> x2;
	total = total + x2;

	average = total / 2.0;
	cout << "The average is " << average << "\n";
	return 0;
}

