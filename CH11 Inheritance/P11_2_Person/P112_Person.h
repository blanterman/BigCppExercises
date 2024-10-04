/*	Exercise P11.2. Implement a base class Person. Derive classes Student and 
Instructor from Person. A person has a name and a birthday. A student has a 
major, and an instructor has a salary. Write the class definitions, the 
constructors, and the member functions print() for all classes.

Bryson Lanterman 20190221
*/
#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Person
{
public:
	/**
		Constructs a person object with a name and a birthday.
		@param n name of person object
		@param bd persons birthday
	*/
	Person(string n, string bd);
	/**
		Returns the name of the person
		@return name of person
	*/
	string get_name() const;
	/**
	Returns the birthday of the person
	@return birthday of person
	*/
	string get_birthday() const;
	/**
		Prints the persons name and birthday
	*/
	virtual void print();

private:
	string name;
	string birthday;
};
