// P63.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Address.h"
#include <iostream>
#include <string>

int main()
{
	int hn = 0, pc = 0;
	string st, c, s, an, resp, remdr;

	cout << "Provide an address:" << endl;
	cout << "House Number: ";
	cin >> hn;
	getline(cin,remdr);
	cout << "Street: ";
	getline(cin, st);
	cout << "Apartment number: ";
	getline(cin, an);
	cout << "City: ";
	getline(cin, c);
	cout << "State: ";
	getline(cin, s);
	cout << "Postal Code: ";
	cin >> pc;
	Address A1(hn, st, an, c, s, pc);
	

	cout << "Provide another address:" << endl;
	cout << "House Number: ";
	cin >> hn;
	getline(cin,remdr);
	cout << "Street: ";
	getline(cin, st);
	cout << "Apartment number: ";
	getline(cin, an);
	cout << "City: ";
	getline(cin, c);
	cout << "State: ";
	getline(cin, s);
	cout << "Postal Code: ";
	cin >> pc;
	Address A2(hn, st, an, c, s, pc);
	
	bool fstfst = A1.comes_before(A2);

	if (fstfst)
	{
		A1.print_address();
		A2.print_address();
	}
	else
	{
		A2.print_address();
		A1.print_address();
	}
	return 0;
}

