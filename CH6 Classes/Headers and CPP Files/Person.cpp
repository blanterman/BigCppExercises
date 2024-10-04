#include "stdafx.h"
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
	name = "Joe Smith";
	age = 0;
}

Person::Person(string pname)
{
	name = pname;
	age = 0;
}

Person::Person(string pname, int page)
{
	name = pname;
	age = page;
}

string Person::get_name() const
{
	return name;
}

int Person::get_age() const
{
	return age;
}