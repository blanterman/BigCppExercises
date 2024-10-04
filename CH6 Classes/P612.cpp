// P612.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include <iostream>

using namespace std;

int main()
{
	Car my_beemer(29);
	my_beemer.add_gas(20);
	my_beemer.drive(100);
	cout << my_beemer.get_gas() << "\n";
	return 0;
}

