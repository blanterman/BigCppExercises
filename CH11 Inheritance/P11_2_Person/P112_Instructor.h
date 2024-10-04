/*	Exercise P11.2. Implement a base class Person. Derive classes Student and
Instructor from Person. A person has a name and a birthday. A student has a
major, and an instructor has a salary. Write the class definitions, the
constructors, and the member functions print() for all classes.

Bryson Lanterman 20190221
*/
#include "stdafx.h"
#include "P112_Person.h"

class Instructor : public Person
{
public:
	/**
		Constructs an Instructor with a name birthday and salary
		@param n name of instructor
		@param bd birthday of instructor
		@param s salary of instructor
	*/
	Instructor(string n, string bd, double s);
	/**
		Returns the salary of the instructor
		@return salary of the instrutor
	*/
	double get_salary() const;
	/**
		Prints the information of the instructor
	*/
	virtual void print();
private:
	double salary;
};