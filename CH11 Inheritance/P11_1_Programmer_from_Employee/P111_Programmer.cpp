/*	exercise P11.1. Derive a class Programmer from Employee. supply a 
constructor Programmer(string name, double salary) that calls the base-class
constructor. Supply a function get_name that returns the name in the format 
"Hacher, Harry (Programmer)".

Bryson Lanterman 20190219
*/
#include "stdafx.h"
#include "P111_Programmer.h"

Programmer::Programmer(string name, double salary)
	:Employee(name, salary)
{

}

string Programmer::get_name() const
{
	return Employee::get_name() + " (Programmer)";
}