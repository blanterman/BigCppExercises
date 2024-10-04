#include "stdafx.h"
#include "P114_Checking.h"
#include <iostream>

using namespace std;

Checking::Checking()
	:Account()
{

}

Checking::Checking(double initialBalance)
	:Account(initialBalance)
{

}

void Checking::daily_interest()
{
	if (Account::get_balance() > 1000.00)
	{
		Account::daily_interest(0.03);
	}
	else
	{
		cout << "Not enough funds yet for interest to be applied.\n";
	}
}