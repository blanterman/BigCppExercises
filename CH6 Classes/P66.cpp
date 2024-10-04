// P66.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bank.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	bool cont = true;
	string optn, acct;
	double amnt = 0.0;
	cout << "Creating account.\n";
	Bank b;
	while (cont)
	{
		cout << "What transaction would you like to make?\n\n"
			<< "(c) print balances\n"
			<< "(d) deposit\n"
			<< "(w) withdrawl\n"
			<< "(t) transfer\n"
			<< "(q) quit" << endl;
		cin >> optn;
		if(optn == "c")
			b.print_balances();
		
		else if(optn == "d")
		{
			cout << "How much would you like to deposit? ";
			cin >> amnt;
			cout << "Which account would you like to deposit to? S or C? ";
			cin >> acct;
			b.deposit(amnt, acct);
		}
		else if(optn == "w")
		{
			cout << "How much would you like to withdraw? ";
			cin >> amnt;
			cout << "Which account would you like to withdraw from? S or C? ";
			cin >> acct;
			b.withdraw(amnt, acct);
		}
		else if(optn == "t")
		{
			cout << "How much would you like to transfer? ";
			cin >> amnt;
			cout << "Which account would you like to transfer from? S or C? ";
			cin >> acct;
			b.transfer(amnt, acct);
		}
		else if(optn == "q")
			cont = false;
		else
			cout << "Invalid choice." << endl;
	}
	
	return 0;
}

