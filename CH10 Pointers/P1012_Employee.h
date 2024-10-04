/*	Ecercise P10.12. Add a method

void Employee::format(char buffer[], int buffer_maxlength)

to the Employee class. The method should fill the buffer with the name and 
salary of the employee. Be sure not to overrun the buffer. It can hold 
buffer_maxlength characters, not counting the '\0' terminator. (That is, the 
buffer has buffer_maxlength + 1 bytes available.) Be sure to provide a '\0' 
terminator.

Bryson Lanterman 20190102
*/

#include "stdafx.h"
#include <string>

using namespace std;

/**
   A basic employee class that is used in many examples
   in the book "Computing Concepts with C++ Essentials"
*/
class Employee
{
public:
   /**
      Constructs an employee with empty name and no salary.
   */
   Employee();
   /**
      Constructs an employee with a given name and salary.
      @param employee_name the employee name
      @param initial_salary the initial salary
   */
   Employee(string employee_name, double initial_salary);
   /**
      Sets the salary of this employee.
      @param new_salary the new salary value
   */
   void set_salary(double new_salary);
   /**
      Gets the salary of this employee.
      @return the current salary
   */
   double get_salary() const;
   /**
      Gets the name of this employee.
      @return the employee name
   */
   string get_name() const;
	/**
		Fills the buffer with the name and salary of the employee.
		@param buffer character string that will hold the name and salary
		@param buffer_maxlength number of characters buffer can hold
	*/
   void format(char buffer[], int buffer_maxlength);
private:
   string name;
   double salary;
};

