// P419.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const double delta_t = 0.01;
const double g = 9.8;

int main()
{
	double init_ht = 0.1;
	double s = 0, v = 0, t = 0, h = 0, vo = 0;
	int count = 0;

	s = init_ht;

	cout << "What is the initial velocity?";
	cin >> v;

	vo = v;
	h = init_ht;

	while (s > 0)
	{
		if (count % 100 == 0)
		{
			cout << "cSec: " << count << "\n"
				<< "Height: " << s << "\n"
				<< "Velocity: " << v << "\n"
				<< "Equation: " << h << "\n\n";
		}
		s = s + v * delta_t;
		v = v - g * delta_t;
		count++;
		t = count/100.0;
		h = -(1.0/2.0) * g * t * t + vo * t + init_ht;
		
	}
	cout << "cSec: " << count << "\n"
		<< "Height: " << s << "\n"
		<< "Velocity: " << v << "\n"
		<< "Equation: " << h << "\n\n";
	return 0;
}

