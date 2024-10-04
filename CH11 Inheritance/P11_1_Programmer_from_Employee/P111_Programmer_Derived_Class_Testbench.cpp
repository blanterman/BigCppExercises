/*	exercise P11.1. Derive a class Programmer from Employee. supply a 
constructor Programmer(string name, double salary) that calls the base-class
constructor. Supply a function get_name that returns the name in the format 
"Hacher, Harry (Programmer)".

Bryson Lanterman 20190219
*/
#include "stdafx.h"
#include "P111_Programmer.h"
#include <iostream>

using namespace std;

int main ()
{
	Programmer P1("Hacker, Harry", 100000.0);
	cout << P1.get_name() << "\n";
	return 0;
}