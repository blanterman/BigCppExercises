#include "stdafx.h"
#include "Address.h"
#include <iostream>
#include <string>

using namespace std;

Address::Address(int AhouseNum, string Astreet, string Acity, string Astate, int ApostalCode)
{
	houseNum = AhouseNum;
	street = Astreet;
	city = Acity;
	state = Astate;
	postalCode = ApostalCode;
}

Address::Address(int AhouseNum, string Astreet, string AaptNum, string Acity, string Astate, int ApostalCode)
{
	houseNum = AhouseNum;
	street = Astreet;
	aptNum = AaptNum;
	city = Acity;
	state = Astate;
	postalCode = ApostalCode;
}

void Address::print_address() const
{
	cout << houseNum << " " << street;
	if (!aptNum.empty())
	{
		cout << " " << aptNum;
	}
	cout << "\n" << city << ", " << state << " " << postalCode << "\n" << endl;
	
}
bool Address::comes_before(Address given) const
{
	return postalCode < given.postalCode;
}