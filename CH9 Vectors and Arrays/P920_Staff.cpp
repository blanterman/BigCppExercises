/*	Exercise P9.20. Define a class

class Staff
{
public:
	. . .
private:
	vector<Employee> members;
};

and implement the find and raise_salary procedures for the Staff data type.


Bryson Lanterman 20180919
*/
#include "stdafx.h"
#include "P920_Staff.h"

using namespace std;


P920_Staff::P920_Staff()
{
}
P920_Staff::P920_Staff(vector<P920_Employee> membersIn)
{
	members = membersIn;
}

void P920_Staff::add_employee(P920_Employee eNew)
{
	members.push_back(eNew);
}

vector<P920_Employee> P920_Staff::find_salaries_between(double low, double high)
{
	vector<P920_Employee> found;
	for (int i = 0; i < members.size(); i++)
	{
		if (low <= members[i].get_salary() && members[i].get_salary() <= high)
		{
			found.push_back(members[i]);
		}
	}
	return found;
}

void P920_Staff::raise_salary(int index, double percent)
{
	members[index].set_salary(members[index].get_salary() * (1 + percent/100.0));
}

int P920_Staff::get_employee_index(string name) const
{
	int matchIndex;
	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].get_name() == name)
		{
			matchIndex = i;
		}
	}
	return matchIndex;
}
