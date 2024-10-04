#pragma once
#include "stdafx.h"

class Account
{
public:
	/**
		Constructs an account with no balance
	*/
	Account();
	/**
		Constructs an account with given initial balance
		@param initialBalance initial balance of account
	*/
	Account(double initialBalance);
	/**
		Deposits funds into an account
		@param amount amount of funds to be added to account
	*/
	void deposit(double amount);
	/**
		Withdrawls funds from an account
		@param amount amount to be withdrawn from accout
	*/
	void withdrawl(double amount);
	/**
		Calculates and adds daily interest at the given monthly rate
	*/
	void daily_interest(double rate);
	/**
		Returns current balance of account
	*/
	double get_balance() const;
private:
	double balance;
};