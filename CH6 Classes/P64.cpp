// P64.cpp : Defines the entry point for the console application.
// This is P65 also

#include "stdafx.h"
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool transact = true;
	string optn;
	double bal = 0.0, amnt = 0.0, rate = 0.0;
	int periods = 0;

	cout << "Creating account.\n";
	cout << "Initial balance: ";
	cin >> bal;

	Account A1(bal);

	cout << "Account Created" << endl;

	while (transact)
	{
		cout << "What transaction would you like to make?\n\n"
			<< "(c) check balance\n"
			<< "(i) comute interest\n"
			<< "(d) deposit\n"
			<< "(w) withdrawl\n"
			<< "(t) interest test\n"
			<< "(q) quit" << endl;
		cin >> optn;
		if(optn == "c")
			cout << "Current balance: $" << A1.check_balance() << endl;
		else if(optn == "i")
		{
			cout << "What is the interest rate per period? ";
			cin >> rate;
			cout << "How many periods of compound interest? ";
			cin >> periods;
			A1.comp_interest(rate, periods);
		}
		else if(optn == "d")
		{
			cout << "How much would you like to deposit? ";
			cin >> amnt;
			A1.deposit(amnt);
		}
		else if(optn == "w")
		{
			cout << "How much would you like to withdraw? ";
			cin >> amnt;
			A1.withdrawl(amnt);
		}
		else if(optn == "t")
		{
			rate = .06 / 12.0;
			cout << rate << endl;
			Account A2(10000.0);
			double initialBal = A2.check_balance();
			double testBal = 2.0 * initialBal;
			int pers = 0;
			while(A2.check_balance() < testBal)
			{
				A2.comp_interest(rate, 1);
				pers++;
			}
			cout << "It took " << pers << " months for the account to double from $"
				 << initialBal << " to $" << testBal << "\n"
				 << "The balance is now: $" << A2.check_balance() << endl;
		}
		else if(optn == "q")
			transact = false;
		else
			cout << "Invalid choice." << endl;
	}
	return 0;
}

