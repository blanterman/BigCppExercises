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
#include "P102_Car.h" // Contains #include "P102_Person.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

void assign_owner(const vector<P102_Person*>& owners, string name)
{

}

int main()
{
	// Create Variables and Regex patterns
	string lineIn;
	regex reg1("\Name: ([a-zA-Z]+)");
	regex reg2("\Age: ([0-9]+)");
	regex reg3("\Model: (.+)");
	regex reg4("\Owner: ([a-zA-Z]+)");
	regex reg5("\Driver: ([a-zA-Z]+)");
	smatch matches;
	vector<P102_Person*> people;
	vector<P102_Car*> cars;

	//Pars the input file for People information and car information
	//and populate the people and cars vectors
	while (getline(cin, lineIn))
	{
		if (lineIn == "<People>")
		{
			getline(cin, lineIn);
			string nameIn;
			int ageIn = 0;
			while (lineIn != "</People>")
			{
				regex_search(lineIn, matches, reg1);
				nameIn = matches[1];
				getline(cin, lineIn);
				regex_search(lineIn, matches, reg2);
				ageIn = stoi(matches[1]);
				P102_Person* person = new P102_Person(nameIn);
				person->set_age(ageIn);
				people.push_back(person);
				getline(cin, lineIn);
			}
		}
		getline(cin, lineIn);
		if (lineIn == "<Cars>")
		{
			getline(cin, lineIn);
			string modelIn;
			string ownerName;
			string driverName;
			while (lineIn != "</Cars>")
			{
				regex_search(lineIn, matches, reg3);
				modelIn = matches[1];
				getline(cin, lineIn);
				regex_search(lineIn, matches, reg4);
				ownerName = matches[1];
				getline(cin, lineIn);
				regex_search(lineIn, matches, reg5);
				driverName = matches[1];
				P102_Car* car = new P102_Car(modelIn);
				for (int i = 0; i < people.size(); i++)
				{
					if (people[i]->get_name() == ownerName)
					{
						car->set_owner(people[i]);
					}
				}
				for (int i = 0; i < people.size(); i++)
				{
					if (people[i]->get_name() == driverName)
					{
						car->set_driver(people[i]);
					}
				}
				cars.push_back(car);
				getline(cin, lineIn);
			}
		}
	}

	//Increment the year of each person in the people vector by 1 year
	for (int i = 0; i < people.size(); i++)
	{
		people[i]->set_age(people[i]->get_age() + 1);
	}

	//Print out all the information about the cars.
	for (int i = 0; i < cars.size(); i++)
	{
		cout << "Model: " << cars[i]->get_model() << "\n"
			<< "    Owner Name: " << cars[i]->get_owner()->get_name() << "\n"
			<< "    Owner Age: " << cars[i]->get_owner()->get_age() << "\n"
			<< "    Driver Name: " << cars[i]->get_driver()->get_name() << "\n"
			<< "    Driver Age: " << cars[i]->get_driver()->get_age() << "\n\n";
	}
	return 0;
}