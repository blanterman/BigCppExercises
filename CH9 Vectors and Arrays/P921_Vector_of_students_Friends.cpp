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
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void extract_info(vector<P921_Student>& FList, string lineRead)
{
	if (lineRead.size() == 0)
		return;

	string name;
	string bDay;

	for(int i = 0; i < lineRead.size(); i++)
	{
		while (lineRead[i] != '\t')
		{
			name.push_back(lineRead[i]);
			i++;
		}
		i++;
		while (i < lineRead.size())
		{
			bDay.push_back(lineRead[i]);
			i++;
		}
	}
	FList.push_back(P921_Student(name, bDay));
}

string extract_month(string bDay)
{
	string date;
	string month;
	string year;
	for (int i = 0; i < bDay.size(); i++)
	{
		while(bDay[i] != ' ')
		{
			date.push_back(bDay[i]);
			i++;
		}
		i++;
		while(bDay[i] != ' ')
		{
			month.push_back(bDay[i]);
			i++;
		}
		i++;
		while (i < bDay.size())
		{
			year.push_back(bDay[i]);
			i++;
		}
	}
	return month;
}

int main()
{
	string lineIn;
	vector<P921_Student> friends;
	string month = "July";
	while (getline(cin, lineIn))
	{
		extract_info(friends, lineIn);
	}
	for (int i = 0; i < friends.size(); i++)
	{
		if (extract_month(friends[i].get_birthday()) == month)
		{
			cout << friends[i].get_name() << "\n";
		}
	}
	return 0;
}