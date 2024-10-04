#include "stdafx.h"
#include "P114_Account.h"
#include <iostream>

using namespace std;

Account::Account()
{
	balance = 0.0;
}

Account::Account(double initialBalance)
{
	balance = initialBalance;
}

void Account::deposit(double amount)
{
	balance += amount;
}

void Account::withdrawl(double amount)
{
	if (balance >= amount)
	{
		balance -= amount;
	}
	else
	{
		cout << "Error, insufficient funds for withdrawl.\n";
	}
}

void Account::daily_interest(double rate)
{
	if (balance > 0)
	{
		balance *= (1 + (rate / 30.0));
	}
}

double Account::get_balance() const
{
	return balance;
}