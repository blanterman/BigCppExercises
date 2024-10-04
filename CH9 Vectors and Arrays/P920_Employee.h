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
#include <string>
#include <vector>

using namespace std;

class P920_Employee
{
public:
	P920_Employee();
	P920_Employee(string employee_name, double initial_salary);

	void set_salary(double new_salary);

	string get_name() const;
	double get_salary() const;
private:
	string name;
	double salary;
};
