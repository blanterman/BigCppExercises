/*	Exercise P10.3. Enhance the Employee class to include a pointer to a
BankAccount. Read in employees and their salaries. Sore them in a
vecotor<Employee>. For each employee, allocate a new bank account on the heap,
except that two consecutive employees with the same last name should share the
same account. Then traverse the vector of employees and, for each employee,
deposit 1/12th of their annual salary into their bank account. Afterwards,
print all employee names and account balances.

Bryson Lanterman 20181016

Exercise P10.4. Enhance the preceding exercise to delete all bank account
objects. Make sure that no object gets deleted twice.

Bryson Lanterman 20181018
*/

#include "stdafx.h"
#include "P103-4_BankAccount.h"
#include <string>

using namespace std;

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
	Sets the account pointer for this employee.
	@param acct BankAccount pointer 
   */
   void set_account(BankAccount* acct);
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
		Gets the pointer to the account for this employee
   */
   BankAccount* get_account();
private:
   string name;
   double salary;
   BankAccount* account;
};