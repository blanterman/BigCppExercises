#include "stdafx.h"

class Account
{
public:
	/**
		Constructs an account with a zero initial balance
	*/
	Account();
	/**
		Constructs an account with the given initial balance
	*/
	Account(double initial_balance);
	/**
		"Deposits" money to the account by adding the given amount.
		@param amnt floating point value for withdrawl
	*/
	void deposit(double amnt);
	/**
		"withdraws" money from the account by subtracting the given amount
		there is a 5 dollar penalty if you try to withdraw more money than is
		available in the account.
		@param amnt floating point value for withdrawl
	*/
	void withdrawl(double amnt);
	/**
		compute the compound interest on the current balance and add it to 
		the current balance.
		@param rate floating point interest rate
		@param periods integer number of periods over which interest is 
	*/
	void comp_interest(double rate, int periods);
	/**
		returns the current balance of the account
		@return balance double value of balance
	*/
	double check_balance() const;
private:
	double balance;
};