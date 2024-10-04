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

class BankAccount
{
public:
	/**
		constructor
	*/
	BankAccount();

	/**
		adds the given amount to the balance
		@param amount amount to add to balance
	*/
	void deposit(double amount);

	/**
		returns the balance
		@return balance the balance of the account
	*/
	double get_balance() const;

private:
	double balance;
};