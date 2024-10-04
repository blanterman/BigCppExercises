#pragma once
#include "stdafx.h"
#include "Person.h"
#include <string>

using namespace std;

class PEmployee
{
public:
	/**
		Constructs an employee with no name and initial salary of 0
	*/
	PEmployee();
	/**
		Constructs an employee with a name and an initial salary
		@param employee_name string name
		@param initial_salary double value of initial salary
	*/
	PEmployee(string employee_name, double initial_salary);
	
	/**
		Sets the value of salary to a new given value
		@param new_salary double new salary value
	*/
	void set_salary(double new_salary);

	/**
		returns the value of the salary
		@return salary double salary value
	*/
	double get_salary() const;

	/**
		returns the name of the employee
		@return name string name
	*/
	string get_name() const;

private:
	Person person_data;
	double salary;

};