/*	Exercise P11.3. Derive a class Manager from Employee. Add a data field, 
named department, of type string. Supply a function print that prints the 
manager's name, department, and salary. Derive a class Executive from Manager.
Supply a function print that prints the string Executive, followed by the 
information stored in the Manager base oject.

Bryson Lanterman 20190222
*/
#include "stdafx.h"
#include "P113_Manager.h"
#include <iostream>

using namespace std;

Manager::Manager()
	:Employee()
{

}

Manager::Manager(string managerName, double initialSalary, string managerDepartment)
	:Employee(managerName, initialSalary)
{
	department = managerDepartment;
}

string Manager::get_department() const
{
	return department;
}

void Manager::print()
{
	cout << "Name: " << Employee::get_name() << "\n"
		<< "Department: " << department << "\n"
		<< "Salary: " << Employee::get_salary() << "\n";
}