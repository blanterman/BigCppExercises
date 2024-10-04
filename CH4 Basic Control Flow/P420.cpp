// P420.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

const double delta_t = 0.01;
const double g = 9.8;
const double PI = 3.14159265358979;
const double d_2_r = PI / 180.0;

int main()
{
	double init_ht = 0.1;
	double sx = 0, sy = 0, v = 0, vx = 0, vy = 0, t = 0, alpha = 0;
	int count = 0;	

	cout << "What is the initial velocity?";
	cin >> v;
	cout << "What is the initial angle?";
	cin >> alpha;
	
	sy = init_ht;
	vx = v * cos(alpha * d_2_r);
	vy = v * sin(alpha * d_2_r);
	
	while (sy > 0)
	{
		if (count % 100 == 0)
		{
			cout << "cSec: " << count << "\n"
				<< "Position: " << sx << ", " << sy << "\n"
				<< "Velocity: " << vx << ", " << vy << "\n\n";
		}
		sx = sx + vx * delta_t;
		sy = sy + vy * delta_t;
		vy = vy - g * delta_t;
		count++;
				
	}
	cout << "cSec: " << count << "\n"
		<< "Position: " << sx << ", " << sy << "\n"
		<< "Velocity: " << vx << ", " << vy << "\n\n";
	return 0;
}

