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
#include "P920_Employee.h"

using namespace std;

class P920_Staff
{
public:
	P920_Staff();
	P920_Staff(vector<P920_Employee> membersIn);

	void add_employee(P920_Employee eNew);

	vector<P920_Employee> find_salaries_between(double low, double high);

	void raise_salary(int index, double percent);

	int get_employee_index(string name) const;
private:
	vector<P920_Employee> members;
};