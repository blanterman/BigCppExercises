#include "stdafx.h"
#include "P1012_Employee.h"
#include <sstream>

Employee::Employee()
{  
   salary = 0;
}

Employee::Employee(string employee_name, double initial_salary)
{  
   name = employee_name;
   salary = initial_salary;
}

void Employee::set_salary(double new_salary)
{  
   salary = new_salary;
}

double Employee::get_salary() const
{  
   return salary;
}

string Employee::get_name() const
{  
   return name;
}

void Employee::format(char buffer[], int buffer_maxlength)
{

	ostringstream streamObj;
	streamObj << fixed;
	streamObj << salary;
	strncpy(buffer, name.c_str(), buffer_maxlength);
	strncat(buffer, streamObj.str().c_str(), buffer_maxlength);
}
