/*	Exercise P11.3. Derive a class Manager from Employee. Add a data field, 
named department, of type string. Supply a function print that prints the 
manager's name, department, and salary. Derive a class Executive from Manager.
Supply a function print that prints the string Executive, followed by the 
information stored in the Manager base oject.

Bryson Lanterman 20190222
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
   virtual string get_name() const;
private:
   string name;
   double salary;
};
