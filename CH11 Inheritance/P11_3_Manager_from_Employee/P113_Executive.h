/*	Exercise P11.3. Derive a class Manager from Employee. Add a data field, 
named department, of type string. Supply a function print that prints the 
manager's name, department, and salary. Derive a class Executive from Manager.
Supply a function print that prints the string Executive, followed by the 
information stored in the Manager base oject.

Bryson Lanterman 20190222
*/
#include "stdafx.h"
#include "P113_Manager.h"

class Executive : public Manager
{
public:
	/**
		Constructs an executive with empty name and department, and no salary
	*/
	Executive();
	/**
		Constructs an executive with given name, salary, and department
		@param executiveName name of executive
		@param initialSalary initial salary of executive
		@param executiveDepartment department that the executive manages
	*/
	Executive(string executiveName, double initialSalary, string executiveDepartment);
	/**
		Prints the string Executive followed by the information stored in the manager base class
	*/
	virtual void print();
};