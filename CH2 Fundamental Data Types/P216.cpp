// P216.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323;
const double DEG2RAD = PI / 180.0;

int main()
{
	cout << fixed << setprecision(4);
	cout << setw(12) << "0 degrees: " << setw(8) << sin(0) << " " << setw(8) << cos(0) << "\n";
	cout << setw(12) << "30 degrees: " << setw(8) << sin(30 * DEG2RAD) << " " << setw(8) << cos(30 * DEG2RAD) << "\n";
	cout << setw(12) << "45 degrees: " << setw(8) << sin(45 * DEG2RAD) << " " << setw(8) << cos(45 * DEG2RAD) << "\n";
	cout << setw(12) << "60 degrees: " << setw(8) << sin(60 * DEG2RAD) << " " << setw(8) << cos(60 * DEG2RAD) << "\n";
	cout << setw(12) << "90 degrees: " << setw(8) << sin(90 * DEG2RAD) << " " << setw(8) << cos(90 * DEG2RAD) << "\n";

    return 0;
}

