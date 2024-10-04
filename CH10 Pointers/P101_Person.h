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

4 Files needed: P101_Person.h, P101_Person.cpp, P101_Person_BFF_Reader.cpp, P101_persons.txt

*/

#include "stdafx.h"
#include <string>

using namespace std;

class P101_Person
{
public:
	/*
		Default constructor
	*/
	P101_Person();

	/*
		Constructor with name given
	*/
	P101_Person(string nameIn);

	/*
		Sets the name of the person
		@param nameIn name of person
	*/
	void set_name(string nameIn);

	/*
		sets the pointer to the person's best friend
		@param bffIn pointer to persons best friend
	*/
	void set_best_friend(P101_Person* bffIn);

	/*
		Increments the count of people that have this person
		as their best friend
	*/
	void increment_popularity();

	/*
		Gets the persons name
		@return name name of the person
	*/
	string get_name() const;

	/*
		Gets the name of the persons best friend
		@return bffName name of the persons bff
	*/
	string get_bff_name() const;

	/*
		Get the popularity count of the person
		@return popularity count of people that have this person as their bff
	*/
	int get_popularity() const;

private:
	string name;
	P101_Person* bff;
	int popularity;
};
