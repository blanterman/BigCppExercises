#include "stdafx.h"
#include "Account.h"
#include <string>

using namespace std;

class Bank
{
public:
	/**
		Constructor that constructs a bank object with 2 accounts: checking and savings
	*/
	Bank();

	/**
		Deposits the given amount into the given account
		@param amount double amount to deposit
		@param account string describing the account S or C
	*/
	void deposit(double amount, string account);

	/**
		Withdraws the given amount from the given account
		@param amount double amount to withdraw
		@param account string describing the account S or C
	*/
	void withdraw(double amount, string account);

	/**
		Transfers the given amount from the given account to the non given account
		@param amount double amount to transfer
		@param account string describing the account S or C from which to transfer
	*/
	void transfer(double amount, string account);

	/**
		Prints the balances of the accounts
	*/
	void print_balances() const;

private:
	// data fields
	Account checking;
	Account savings;
};