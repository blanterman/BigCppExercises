#include "stdafx.h"
#include "Bank.h"
#include <string>
#include <iostream>

using namespace std;

Bank::Bank()
{
	Account savings;
	Account checking;
}

void Bank::deposit(double amount, string account)
{
	if(account == "S")
		savings.deposit(amount);
	else if(account == "C")
		checking.deposit(amount);
	else
		cout << "Incorrect account selection" << endl;
}

void Bank::withdraw(double amount, string account)
{
	if(account == "S")
		savings.withdrawl(amount);
	else if(account == "C")
		checking.withdrawl(amount);
	else
		cout << "Incorrect account selection" << endl;
}

void Bank::transfer(double amount, string account)
{
	if(account == "S")
	{
		if(savings.check_balance() >= amount)
		{
			savings.withdrawl(amount);
			checking.deposit(amount);
		}
		else
			cout << "Insufficient Funds" << endl;
	}
	else if(account == "C")
	{
		if (checking.check_balance() >= amount)
		{
			checking.withdrawl(amount);
			savings.deposit(amount);
		}
		else
			cout << "Insufficient Funds" << endl;
	}
	else
		cout << "Incorrect account selection" << endl;
}

void Bank::print_balances() const
{
	cout << "Checking: " << checking.check_balance() << "\n"
		 << "Savings: " << savings.check_balance() << endl;
}