/*	Exercise P9.21. Design a class Student, or use one from a previous 
exercise. A student has a name and a birthday.l Make a vector

vector<Student> friends;

Read a set of names and birthdays in from a file or type them in, thus 
populating the friends vector. Then print out all friends whose birthday 
falls in the current month.

Bryson Lanterman 20180919
*/
#include "stdafx.h"
#include "P921_Student.h"

P921_Student::P921_Student()
{

}

P921_Student::P921_Student(string nameIn, string bDayIn)
{
	name = nameIn;
	bDay = bDayIn;
}

string P921_Student::get_name() const
{
	return name;
}

string P921_Student::get_birthday() const
{
	return bDay;
}