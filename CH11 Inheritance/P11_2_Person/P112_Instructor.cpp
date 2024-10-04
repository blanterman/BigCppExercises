/*	Exercise P11.2. Implement a base class Person. Derive classes Student and
Instructor from Person. A person has a name and a birthday. A student has a
major, and an instructor has a salary. Write the class definitions, the
constructors, and the member functions print() for all classes.

Bryson Lanterman 20190221
*/
#include "stdafx.h"
#include "P112_Instructor.h"
#include <iostream>

using namespace std;

Instructor::Instructor(string n, string bd, double s)
	:Person(n, bd)
{
	salary = s;
}
double Instructor::get_salary() const
{
	return salary;
}
void Instructor::print()
{
	cout << "---Instructor---\n"
		<< "Name: " << Person::get_name() << "\n"
		<< "Birthday: " << Person::get_birthday() << "\n"
		<< "Salary: " << salary << "\n";
}