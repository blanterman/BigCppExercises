/*	Exercise P11.2. Implement a base class Person. Derive classes Student and
Instructor from Person. A person has a name and a birthday. A student has a
major, and an instructor has a salary. Write the class definitions, the
constructors, and the member functions print() for all classes.

Bryson Lanterman 20190221
*/
#include "stdafx.h"
#include "P112_Person.h"

class Student : public Person
{
public:
	/**
		Constructs a Student object
		@param n name of student
		@param bd birthday of student
		@param mjr major of the student
	*/
	Student(string n, string bd, string mjr);
	/**
	Returns the major of the Student
	@return major of student
	*/
	string get_major() const;
	/**
		Prints out the student's information
	*/
	virtual void print();
private:
	string major;
};
