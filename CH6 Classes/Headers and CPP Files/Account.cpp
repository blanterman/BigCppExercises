#include "stdafx.h"
#include "Account.h"
#include <iostream>

using namespace std;

Account::Account()
{
	balance = 0.0;
}

Account::Account(double initial_balance)
{
	balance = initial_balance;
}

void Account::deposit(double amnt)
{
	balance += amnt;
}
	
void Account::withdrawl(double amnt)
{
	if (amnt > balance)
	{
		cout << "Error: You are trying to withdraw more money than is available.\n"
			 << "You will be charged $5, and the withdrawl will not go through." << endl;
		balance -= 5.0;
	}
	else
	{
		balance -= amnt;
	}
}

void Account::comp_interest(double rate, int periods)
{
	balance *= pow((1.0 + rate),periods);
}

double Account::check_balance() const
{
	return balance;
}