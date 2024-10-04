#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Person
{
public:
	/**
		Constructs a person with a blank name and age 0
	*/
	Person();

	/**
		Constructs a person with given name and age 0
		This is used when an age is ommited.
		@param pname string name
	*/
	Person(string pname);

	/**
		Constructs a person with given name and age 0
		@param pname string name
		@param page integer age
	*/
	Person(string pname, int page);

	/**
		Returns the name of the person
		@return name string age of person
	*/
	string get_name() const;

	/**
		Returns the age of the person
		@return age integer age of person
	*/
	int get_age() const;

private:
	string name;
	int age; /* 0 if unknown */

};