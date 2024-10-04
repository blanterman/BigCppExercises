#include "stdafx.h"
#include "P114_Account.h"

class Checking : public Account
{
public:
	/**
		Constructs a checking account with no balance
	*/
	Checking();
	/**
		Constructs a checking account with given initial balance
	*/
	Checking(double initialBalance);
	/**
		Computes and adds daily interest at 3% monthly if balance is over $1000
	*/
	void daily_interest();
private:
};