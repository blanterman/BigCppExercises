#include "stdafx.h"
#include "P919_Transaction.h"
#include <iostream>



P919_Transaction::P919_Transaction()
{
}

P919_Transaction::P919_Transaction(int dateIn, double amountIn, string descriptionIn)
{
	date = dateIn;
	amount = amountIn;
	description = descriptionIn;
}



void P919_Transaction::print_transaction()
{
	cout <<  date << "\t" << amount << "\t" << description << "\n";
	/*
	double balance = 0.0;
	double minDailyBal = DBL_MAX;
	double averageDailyBal = 0.0;
	double balSum = 0.0;
	for(int i = 0; i < dates.size(); i++)
	{
		cout << dates[i] << "\t" << amounts[i] << "\t" << descriptions[i] << "\n";
		balance += amounts[i];
		balSum += balance;
		if(balance < minDailyBal)
		{
			minDailyBal = balance;
		}
	}
	averageDailyBal = balSum / NUMDAYS;
	double ADBInterest = RATE * averageDailyBal;
	double MDBInterest = RATE * minDailyBal;
	cout << "Balance: " << balance << "\n"
		<< "MDB Interest earned: " << MDBInterest << "\n"
		<< "ADB Interest earned: " << ADBInterest << "\n";
		*/
}

double P919_Transaction::get_amount() const
{
	return amount;
}