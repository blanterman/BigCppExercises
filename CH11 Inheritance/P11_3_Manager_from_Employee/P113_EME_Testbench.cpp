/*	Exercise P11.3. Derive a class Manager from Employee. Add a data field, 
named department, of type string. Supply a function print that prints the 
manager's name, department, and salary. Derive a class Executive from Manager.
Supply a function print that prints the string Executive, followed by the 
information stored in the Manager base oject.

Bryson Lanterman 20190222
*/
#include "stdafx.h"
#include "P113_Executive.h"

int main()
{
	Employee e1("Bryson Lanterman", 30000.0);
	Manager m1("Shannon Lanterman", 180000.0, "Everything");
	Employee e2;
	Manager m2;
	m1.print();
	m2.print();
	Executive ex1;
	Executive ex2("Jane Lanterman", 1000000.0, "Bryson and Shannon");
	ex1.print();
	ex2.print();
	return 0;
}