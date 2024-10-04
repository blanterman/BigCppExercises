#include "stdafx.h"
#include "PEmployee.h"
#include "Person.h"
#include <string>

using namespace std;

PEmployee::PEmployee()
{
	salary = 0.0;
}

PEmployee::PEmployee(string employee_name, double initial_salary)
{
	person_data = Person(employee_name);
	salary = initial_salary;
}

void PEmployee::set_salary(double new_salary)
{
	salary = new_salary;
}

double PEmployee::get_salary() const
{
	return salary;
}

string PEmployee::get_name() const
{
	return person_data.get_name();
}