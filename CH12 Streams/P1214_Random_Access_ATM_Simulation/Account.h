#include "stdafx.h"

#ifndef CCC_EMPL_H
#define CCC_EMPL_H

#include <string>

using namespace std;

/**
   A basic account class 
*/
class Account
{
public:
   /**
      Constructs an account with empty account number and no balance.
   */
   Account();
   /**
      Constructs an Account with a given account number and balance.
      @param account_num the account number
      @param initial_balance the initial balance
   */
   Account(string account_number, double initial_balance);
   /**
      Sets the balance of this account.
      @param new_balance the new balance value
   */
   void set_balance(double new_balance);
   /**
      Gets the balance of this account.
      @return the current balance
   */
   double get_balance() const;
   /**
      Gets the account number of this account.
      @return the account number
   */
   string get_number() const;
private:
   string number;
   double balance;
};

#endif
