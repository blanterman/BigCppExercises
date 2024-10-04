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
#include "P103-4_Employee.h" // this has #include "P103_BankAccount.h"
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/**
	Deposits 1/12 of their salary into the employee's account.
	@param v vector of employee objects
*/
void payday(vector<Employee>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i].get_account()->deposit(v[i].get_salary() / 12.0);
	}
}

void delete_accounts(vector<Employee>& v)
{
	BankAccount* buffer = NULL;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].get_account() == buffer)
		{
			v[i].set_account(NULL);
		}
		else
		{
			buffer = v[i].get_account();
			delete v[i].get_account();
			v[i].set_account(NULL);
		}
	}
	buffer = NULL;
	
}
/**
	Prints the entire staff with name and account balance
	@param v vector of employee objects.
*/
void print_staff(vector<Employee>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Name: " << v[i].get_name() << "\n";
		if (v[i].get_account() == NULL)
		{
			cout << "NO Account for this employee \n\n";
		}
		else
		{
			cout << "Account Balance: " << v[i].get_account()->get_balance() << "\n\n";
		}

	}
}

int main()
{
	// Empty vector of employees
	vector<Employee> staff;

	// Regex objects to be used as Staff.txt file is parsed
	regex regLastName("\Name: (([a-zA-Z]+), [a-zA-Z]+)"); // Captures last name
	regex regSalary("\Salary: ([0-9]+\.?[0-9]{2}?)"); // Captures Salary
	smatch matches;

	// String variables to be used in parsing and object creation
	string lineIn;
	string nameIn;
	string lastName;
	string lastNameBuffer = ""; // buffer 1 last name so that consecutive 
								// entries with the same last name get the
								// same account object pointer
	double salary;

	// Staff.txt parsing loop
	while (getline(cin, lineIn)) // gets next line, should always be a name line
	{
		regex_search(lineIn, matches, regLastName); // Parse name line, capture full name and last name
		nameIn = matches[1];						// full name for Employee object
		lastName = matches[2];						// last name to check against buffer
		getline(cin, lineIn);						// get next line. should always be a Salary line	
		regex_search(lineIn, matches, regSalary);	// Parse salaray line, capture the salary		
		salary = stod(matches[1]);					// salary value for Employee object
		
		// All information to add an Employee to Staff vector now parsed.
		
		// Create objects and pointers
		Employee e(nameIn, salary);					// Create Employee object
		BankAccount* ba = new BankAccount();		// Create a new BankAccount object pointer
		
		// Checks the last name parsed against the previous entry's last name
		if (lastName == lastNameBuffer)  
		{
			// same last name gets the account of the LAST entry in the Staff vector
			// If there was no last name captured this will be reached by the first
			// Employee and there will be an error.
			e.set_account(staff[staff.size() - 1].get_account());
		}
		else
		{
			// New last name gets the new account object pointer
			e.set_account(ba);
		}

		// Add the Employee to the end of the Staff vector
		staff.push_back(e);

		// Update last name buffer
		lastNameBuffer = lastName;
	}

	// Pay the staff for the month.
	payday(staff);

	// Print the staff names and account balances
	print_staff(staff);

	// Delete all the accounts.
	delete_accounts(staff);

	// Print the staff names and account balances
	print_staff(staff);

	return 0;
}