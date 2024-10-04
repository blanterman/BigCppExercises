/*	Exercise P11.2. Implement a base class Person. Derive classes Student and
Instructor from Person. A person has a name and a birthday. A student has a
major, and an instructor has a salary. Write the class definitions, the
constructors, and the member functions print() for all classes.

Bryson Lanterman 20190221
*/
#include "stdafx.h"
#include "P112_Student.h"
#include "P112_Instructor.h"

int main()
{
	Person p1("Bryson Lanterman", "6 July 1984");
	p1.print();
	Student s1("Shannon Lanterman", "31 July 1985", "Psychology");
	s1.print();
	Instructor i1("Dean Wheeler", "17 August 1959", 150000.00);
	i1.print();
	return 0;
}