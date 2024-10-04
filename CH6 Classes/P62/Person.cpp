#include "stdafx.h"
#include "Person.h"
#include <string>

using namespace std;

Person::Person()
{
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