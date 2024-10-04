/*	Exercise P9.19. Write a program that prints out a bank statement. The 
program input is a sequence of transactions. Each transaction has the form

day amount description

For example, 

15 -224 Check 2140
16 1200 ATM deposit

Your program should read in the desciptions and then print out a staement 
listing all deposits, whithdrawals, and the daily palance for each day. You 
should then compute the interest earned by the account. Use both the minimum 
daily palance and the average daily balance methods for computing interest, 
and print out both values. Use an interest rate of 0.5 percent per month, and 
assume the month has 30 days. You may assume  that the input data are sorted 
by the date. You may also assume that the first entry is of the form 

1 1143.24 Inintial balance


Bryson Lanterman 20180917
*/

#include "stdafx.h"
#include "P919_Transaction.h"
#include <iostream>
#include <string>
#include <vector>



using namespace std;

const double RATE = 0.005;
const double NUMDAYS = 31.0;

/**
	Extracts the amount information of the transaction information and pushes 
	it onto a given vector of amounts.
	@param transaction transaction information string
	@param amountVector vector of amounts.
*/
void add_transaction(string transaction, vector<P919_Transaction>& account)
{
	string dateString;
	string amountString;
	string description;

	int date = 0;
	double amount = 0.0;

	for (int i = 0; i < transaction.size(); i++)
	{
		while (transaction[i] != ' ')
		{
			dateString.push_back(transaction[i]);
			i++;
		}
		date = stoi(dateString);
		i++;
		while(transaction[i] != ' ')
		{
			amountString.push_back(transaction[i]);
			i++;
		}
		amount = stod(amountString);
		i++;
		while(i < transaction.size())
		{
			description.push_back(transaction[i]);
			i++;
		}
		P919_Transaction transaction(date, amount, description);
		account.push_back(transaction);
	}
}

void print_statement(vector<P919_Transaction> account)
{
	double balance = 0.0;
	double minDailyBal = DBL_MAX;
	double averageDailyBal = 0.0;
	double balSum = 0.0;
	for(int i = 0; i < account.size(); i++)
	{
		account[i].print_transaction();
		balance += account[i].get_amount();
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
}


int main()
{
	string transaction;
	vector<P919_Transaction> account;
	while (getline(cin, transaction))
	{
		add_transaction(transaction, account);
	}
	print_statement(account);
	
	return 0;
}