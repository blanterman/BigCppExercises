#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class P919_Transaction
{
public:
	/**
		Constructs an account with no transactions
	*/
	P919_Transaction();
	/**
		Constructs an account with the given initial transaction
	*/
	P919_Transaction(int date, double amount, string description);

	/**
		prints out all of the transactions
		@param amnt floating point value for withdrawl
	*/
	void print_transaction();

	/**
		returns the amount
		@return amount the amount value
	*/
	double get_amount() const;

private:
	int date;
	double amount;
	string description;
};