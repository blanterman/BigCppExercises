/*	Exercise P10.1. Implement a class Person with thefollowing fields:

* the name
* a pointer to the person's best friend
* a popularity counter that indicates how many other people  have this
person as their best friend

Write a program that reads in a list of names, allocates a new Person for each
of them, and stores them in a vector<Person*>. Then ask the name of the best
friend for each of the Person objects. Locate the object matching the firend's
name and call a set_best_friend method to update the pointer and counter.
Fincally, print out all Person objects, listing the name, best friend, and
popularity counter for each.

BJL Notes:

This program reads from a text file. The file is organized as follows:
<textFile>  // not written in file
name1
name2
.
.
.
nameN
<Break>
name-of-bff-of-name1
name-of-bff-of-name2
.
.
.
name-of-bff-of-nameN
</testFile>  // not written in file

First is the list of names. This is used to populate the vector of persons.
This is followed by the keyword <Break> so the program knows when to stop
populating the vector.
Last is the list of best friends (bff). The first bff is the bff of the
person in vector index 0. The second bff is the bff of the person in vector
index 1 etc etc. EACH BFF NAME MUST EXIST AS A NAME IN THE PERSON VECTOR!

Bryson Lanterman 20181012

4 Files needed: P101_Person.h, P101_Person.cpp, P101_Person_BFF_Reader.cpp, P101_Persons.txt

*/

#include "stdafx.h"
#include "P101_Person.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void print_persons(const vector<P101_Person*>& listOfPersons)
{
	for (int i = 0; i < listOfPersons.size(); i++)
	{
		cout << "Name of Person: " << listOfPersons[i]->get_name() << "\n"
			<< "    BFF: " << listOfPersons[i]->get_bff_name() << "\n"
			<< "    Popularity Count: " << listOfPersons[i]->get_popularity() << "\n";
	}
	cout << "\n";
}

int main()
{
	vector<P101_Person*> persons;
	string nameIn;
	bool getNames = true;
	while (getNames)
	{
		getline(cin, nameIn);
		if (nameIn == "<Break>")
		{
			getNames = false;
		}
		else
		{
			P101_Person* person = new P101_Person(nameIn);
			persons.push_back(person);
		}
		
	}
	for (int i = 0; i < persons.size(); i++)
	{
		getline(cin, nameIn);
		for (int j = 0; j < persons.size(); j++)
		{
			if (nameIn == persons[j]->get_name())
			{
				persons[i]->set_best_friend(persons[j]);
			}
		}
	}

	print_persons(persons);
	


	return 0;
}