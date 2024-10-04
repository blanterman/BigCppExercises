/*	Exercise P11.3. Derive a class Manager from Employee. Add a data field, 
named department, of type string. Supply a function print that prints the 
manager's name, department, and salary. Derive a class Executive from Manager.
Supply a function print that prints the string Executive, followed by the 
information stored in the Manager base oject.

Bryson Lanterman 20190222
*/
#include "stdafx.h"
#include "P113_Employee.h"

class Manager : public Employee
{
public:
	/**
		Constructs a manager with an empty name and department, and no salary
	*/
	Manager();
	/**
		Constructs a manager with given name, salary and department
		@param managerName name of manager
		@param initialSalary initial salary amount
		@param managerDepartment department the manager manages
	*/
	Manager(string managerName, double initialSalary, string managerDepartment);
	/**
		Returns the dapartment of the manager
		@return department department of the manager
	*/
	string get_department() const;
	/**
		Prints the managers name, department, and salary
	*/
	virtual void print();
private:
	string department;
};