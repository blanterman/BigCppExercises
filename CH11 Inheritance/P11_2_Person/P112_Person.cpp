/*	Exercise P11.2. Implement a base class Person. Derive classes Student and
Instructor from Person. A person has a name and a birthday. A student has a
major, and an instructor has a salary. Write the class definitions, the
constructors, and the member functions print() for all classes.

Bryson Lanterman 20190221
*/
#include "stdafx.h"
#include "P112_Person.h"
#include <iostream>

Person::Person(string n, string bd)
{
	name = n;
	birthday = bd;
}
string Person::get_name() const
{
	return name;
}
string Person::get_birthday() const
{
	return birthday;
}
void Person::print()
{
	cout << "---Person---\n" 
		<< "Name: " << name << "\n"
		<< "Birthday: " << birthday << "\n";
}