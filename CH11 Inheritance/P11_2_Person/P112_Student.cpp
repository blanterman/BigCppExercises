/*	Exercise P11.2. Implement a base class Person. Derive classes Student and
Instructor from Person. A person has a name and a birthday. A student has a
major, and an instructor has a salary. Write the class definitions, the
constructors, and the member functions print() for all classes.

Bryson Lanterman 20190221
*/
#include "stdafx.h"
#include "P112_Student.h"
#include <iostream>

using namespace std;

Student::Student(string n, string bd, string mjr)
	:Person(n, bd)
{
	major = mjr;
}
string Student::get_major() const
{
	return major;
}
void Student::print()
{
	cout << "---Student---\n"
		<< "Name: " << Person::get_name() << "\n"
		<< "Birthday: " << Person::get_birthday() << "\n"
		<< "Major: " << major << "\n";
}