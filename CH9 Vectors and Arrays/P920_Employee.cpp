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

P920_Employee::P920_Employee()
{

}

P920_Employee::P920_Employee(string employee_name, double initial_salary)
{
	name = employee_name;
	salary = initial_salary;
}

void P920_Employee::set_salary(double new_salary)
{
	salary = new_salary;
}

string P920_Employee::get_name() const
{
	return name;
}

double P920_Employee::get_salary() const
{
	return salary;
}