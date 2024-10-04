/*	exercise P11.1. Derive a class Programmer from Employee. supply a 
constructor Programmer(string name, double salary) that calls the base-class
constructor. Supply a function get_name that returns the name in the format 
"Hacher, Harry (Programmer)".

Bryson Lanterman 20190219
*/
#include "stdafx.h"
#include "ccc_empl.h"

class Programmer : public Employee
{
public:
	/**
		Default constructor
		@param name name of programmer
		@param salary double salary of programmer
	*/
	Programmer(string name, double salary);
	/**
		Returns the name in the format name (Programmer)
		@return the name of the employee in the format "name (Programmer)"
	*/
	virtual string get_name() const;
};