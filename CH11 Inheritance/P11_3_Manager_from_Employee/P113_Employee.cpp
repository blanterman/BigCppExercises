/*	Exercise P11.3. Derive a class Manager from Employee. Add a data field, 
named department, of type string. Supply a function print that prints the 
manager's name, department, and salary. Derive a class Executive from Manager.
Supply a function print that prints the string Executive, followed by the 
information stored in the Manager base oject.

Bryson Lanterman 20190222
*/
#include "stdafx.h"
#include "P113_Employee.h"

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
