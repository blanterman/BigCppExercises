// P415.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string account, option;
	double bal_sav = 0, bal_check = 0, amount = 0;

	// Get initial Balances of the Accounts
	// Checking
	cout << "What is the initial balance of the checking account?";
	cin >> bal_check;
	if (bal_check < 0)
	{
		cout << "Error: Can not have negative balance.\n";
		return 1;
	}
	// Savings
	cout << "What is the initial balance of the savings account?";
	cin >> bal_sav;
	if (bal_sav < 0)
	{
		cout << "Error: Can not have negative balance.\n";
		return 2;
	}

	// Get the type of transaction
	cout << "Would you like to (d) deposit, (w) withdrawl, or (t) transfer?";
	cin >> option;

	// Handle a deposit
	if (option == "d")
	{
		cout << "To which account would you like to deposit?\n"
			 << "(c) checking or (s) savings?";
		cin >> account;
		if (account == "c")
		{
			cout << "How much would you like to deposit to checking?";
			cin >> amount;
			if (amount < 0)
			{
				cout << "Error: cannot deposit negetive amount.\n";
				return 3;
			}
			bal_check += amount;
		}
		else if (account == "s")
		{
			cout << "How much would you like to deposit to savings?";
			cin >> amount;
			if (amount < 0)
			{
				cout << "Error: cannot deposit negetive amount.\n";
				return 3;
			}
			bal_sav += amount;
		}
		else
		{
			cout << "Error: improper account selection.\n";
			return 4;
		}
	}

	// Handle a withdrawl
	else if (option == "w")
	{
		cout << "From which account would you like to withdraw?\n"
			 << "(c) checking or (s) savings?";
		cin >> account;
		if (account == "c")
		{
			cout << "How much would you like to withdraw from checking?";
			cin >> amount;
			if (amount < 0)
			{
				cout << "Error: cannot withdraw negetive amount.\n";
				return 5;
			}
			else if (bal_check - amount < 0)
			{
				cout << "Error: This transaction would cause an overdraft.\n";
				return 6;
			}
			bal_check -= amount;
		}
		else if (account == "s")
		{
			cout << "How much would you like to withdraw from savings?";
			cin >> amount;
			if (amount < 0)
			{
				cout << "Error: cannot withdraw negetive amount.\n";
				return 7;
			}
			else if (bal_sav - amount < 0)
			{
				cout << "Error: This transaction would cause an overdraft.\n";
				return 8;
			}
			bal_sav -= amount;
		}
		else
		{
			cout << "Error: improper account selection.\n";
			return 4;
		}
	}

	// Handle a transfer
	else if (option == "t")
	{
		cout << "To which account would you like to transfer?\n"
			 << "(c) checking or (s) savings?";
		cin >> account;
		if (account == "c")
		{
			cout << "How much would you like to transfer to checking?";
			cin >> amount;
			if (amount < 0)
			{
				cout << "Error: cannot transfer negetive amount.\n";
				return 5;
			}
			else if (bal_sav - amount < 0)
			{
				cout << "Error: This transaction would cause an overdraft.\n";
				return 6;
			}
			bal_sav -= amount;
			bal_check += amount;
		}
		else if (account == "s")
		{
			cout << "How much would you like to transfer to savings?";
			cin >> amount;
			if (amount < 0)
			{
				cout << "Error: cannot transfer negetive amount.\n";
				return 5;
			}
			else if (bal_check - amount < 0)
			{
				cout << "Error: This transaction would cause an overdraft.\n";
				return 6;
			}
			bal_sav += amount;
			bal_check -= amount;
		}
		else
		{
			cout << "Error: improper account selection.\n";
			return 4;
		}
	}
	else
	{
		cout << "That transaction type is not supported. Goodbye.\n";
		return 9;
	}

	// Print out the final balances after the transaction
	cout << "The new balances of the accouts are:\n"
		 << "Checking: " << bal_check << "\n"
		 << "Savings: " << bal_sav << "\n";

	return 0;
}

