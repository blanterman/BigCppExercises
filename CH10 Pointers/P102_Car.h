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
#include "P102_Person.h"

using namespace std;


class P102_Car
{
public:
	/*
		Constructor
	*/
	P102_Car(string modelIn);

	/*
		Sets Owner Pointer
		@param ownerIn pointer to owner person object
	*/
	void set_owner(P102_Person* ownerIn);

	/*
		Sets Driver Pointer
		@param driverIn pointer to driver person object
	*/
	void set_driver(P102_Person* driverIn);

	/*
		Member functions for getting infomation about the car and driver.
	*/
	string get_model() const;

	// Maybe not Kosher, but I wanted to do it. The more Kosher way
	//may be to just get the information and return that so that the coder
	//doesn't have to hava car->get_owner()->get_name() but can just do
	//car->get_owner_name(). I like this better for some reason.
	P102_Person* get_owner();
	P102_Person* get_driver();

private:
	string model;
	P102_Person* owner;
	P102_Person* driver;
};