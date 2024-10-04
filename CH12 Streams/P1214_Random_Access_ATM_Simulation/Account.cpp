#include "stdafx.h"
#include "Account.h"

Account::Account()
{  
   balance = 0;
}

Account::Account(string account_number, double initial_balance)
{  
   number = account_number;
   balance = initial_balance;
}

void Account::set_balance(double new_balance)
{  
   balance = new_balance;
}

double Account::get_balance() const
{  
   return balance;
}

string Account::get_number() const
{  
   return number;
}
