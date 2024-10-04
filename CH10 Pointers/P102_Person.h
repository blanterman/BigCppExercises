/*	Exercise P10.2. Implement a class Person with two fields name and age, and 
a class Car with three fields:

* the model
* a pointer to the owner (a Person*)
* a pointer to the driver (also a Person*)

Write a program that prompts the user to specify people and cars. Store them in
a vector<Person*> and a vector<Car*>. Traverse the vector of Person objects and
increment their ages by one year. Finally, traverse the vector of cars and 
print out the car model, owner's name and age, and driver's name and age.

Notes: Instead of asking the user for information I made this just read a 
document with start and stop flags where People would be entered by the user
and Cars would be entered by the user with the needed information to populate
the vectors.

Bryson Lanterman 20181015
*/

#include "stdafx.h"
#include <string>

using namespace std;

class P102_Person
{
public:
	/**
		Default Constructor
	*/
	P102_Person();

	/*
		Constructor
	*/
	P102_Person(string nameIn);

	/*
		Set the age
		@param age integer age
	*/
	void set_age(int ageIn);

	/*
		Get the name
		@return name name of person
	*/
	string get_name() const;

	/*
		Get the age
		@return age age of person
	*/
	int get_age() const;
private:
	string name;
	int age;
};