/*	Exercise P11.3. Derive a class Manager from Employee. Add a data field, 
named department, of type string. Supply a function print that prints the 
manager's name, department, and salary. Derive a class Executive from Manager.
Supply a function print that prints the string Executive, followed by the 
information stored in the Manager base oject.

Bryson Lanterman 20190222
*/
#include "stdafx.h"
#include "P113_Executive.h"
#include <iostream>

using namespace std;

Executive::Executive()
	:Manager()
{

}

Executive::Executive(string executiveName, double initialSalary, string executiveDepartment)
	:Manager(executiveName, initialSalary, executiveDepartment)
{

}

void Executive::print()
{
	cout << "Executive\n";
	Manager::print();
}