// P611.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SodaCan.h"
#include <iostream>

using namespace std;

int main()
{
	double height = 2.0;
	double radius = 2.0;
	SodaCan s(height, radius);
	double SA = s.get_surface_area();
	double Vol = s.get_volume();

	cout << "vol: " << Vol << "\n"
		<< "SA : " << SA << endl;
    return 0;
}

