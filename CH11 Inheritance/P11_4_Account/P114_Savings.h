#include "stdafx.h"
#include "P114_Account.h"

class Savings : public Account
{
public:
	/**
		Constructs a savings account with no balance
	*/
	Savings();
	/**
		Constructs a savings account with given initial balance
	*/
	Savings(double initialBalance);
	/**
		Computes and adds daily interest at 6% monthly
	*/
	void daily_interest();
private:
};