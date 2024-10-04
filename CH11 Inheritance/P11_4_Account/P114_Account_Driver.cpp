#include "stdafx.h"
#include "P114_Checking.h"
#include "P114_Savings.h"
#include <vector>
#include <iostream>

using namespace std;

void print_balance(Account& acct)
{
	cout << "Balance: " << acct.get_balance() << "\n";
}

int main()
{
	Account a1;
	a1.deposit(1000.0);
	vector<double> deposits(30);
	deposits[0] = 0;
	deposits[1] = 0;
	deposits[2] = 0;
	deposits[3] = 0;
	deposits[4] = 0;
	deposits[5] = 0;
	deposits[6] = 0;
	deposits[7] = 0;
	deposits[8] = 0;
	deposits[9] = 0;
	deposits[10] = 0;
	deposits[11] = 0;
	deposits[12] = 0;
	deposits[13] = 0;
	deposits[14] = 0;
	deposits[15] = 0;
	deposits[16] = 0;
	deposits[17] = 0;
	deposits[18] = 0;
	deposits[19] = 0;
	deposits[20] = 0;
	deposits[21] = 0;
	deposits[22] = 0;
	deposits[23] = 0;
	deposits[24] = 0;
	deposits[25] = 0;
	deposits[26] = 0;
	deposits[27] = 0;
	deposits[28] = 0;
	deposits[29] = 0;
	vector<double> withdrawls(30);
	withdrawls[0] = 0;
	withdrawls[1] = 0;
	withdrawls[2] = 0;
	withdrawls[3] = 0;
	withdrawls[4] = 0;
	withdrawls[5] = 0;
	withdrawls[6] = 0;
	withdrawls[7] = 0;
	withdrawls[8] = 0;
	withdrawls[9] = 0;
	withdrawls[10] = 0;
	withdrawls[11] = 0;
	withdrawls[12] = 0;
	withdrawls[13] = 0;
	withdrawls[14] = 0;
	withdrawls[15] = 0;
	withdrawls[16] = 0;
	withdrawls[17] = 0;
	withdrawls[18] = 0;
	withdrawls[19] = 0;
	withdrawls[20] = 0;
	withdrawls[21] = 0;
	withdrawls[22] = 0;
	withdrawls[23] = 0;
	withdrawls[24] = 0;
	withdrawls[25] = 0;
	withdrawls[26] = 0;
	withdrawls[27] = 0;
	withdrawls[28] = 0;
	withdrawls[29] = 0;

	for (int i = 0; i < 30; i++)
	{
		a1.deposit(deposits[i]);
		a1.withdrawl(withdrawls[i]);
		print_balance(a1);
		cout << "\n";
	}

	Savings s1(1000.00);
	for (int i = 0; i < 30; i++)
	{
		s1.deposit(deposits[i]);
		s1.withdrawl(withdrawls[i]);
		s1.daily_interest();
		print_balance(s1);
		cout << "\n";
	}

	Checking c1(1001.00);
	for (int i = 0; i < 30; i++)
	{
		c1.deposit(deposits[i]);
		c1.withdrawl(withdrawls[i]);
		c1.daily_interest();
		print_balance(c1);
		cout << "\n";
	}
	return 0;

}