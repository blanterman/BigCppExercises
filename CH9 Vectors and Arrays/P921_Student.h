/*	Exercise P9.21. Design a class Student, or use one from a previous 
exercise. A student has a name and a birthday.l Make a vector

vector<Student> friends;

Read a set of names and birthdays in from a file or type them in, thus 
populating the friends vector. Then print out all friends whose birthday 
falls in the current month.

Bryson Lanterman 20180919
*/

#include "stdafx.h"
#include <string>

using namespace std;

class P921_Student
{
public:
	P921_Student();
	P921_Student(string nameIn, string bDayIn);

	string get_name() const;
	string get_birthday() const;
private:
	string name;
	string bDay;
};
