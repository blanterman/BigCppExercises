#include "stdafx.h"
#include <string>

using namespace std;

class Address
{
public:
	/**
		Constructor with all vars but the aptNum
		@param AhouseNum integer house number
		@param Astreet string street name
		@param Acity string city name
		@param Astate string state name
		@param ApostalCode integer postal code
	*/
	Address(int AhouseNum, string Astreet, string Acity, string Astate, int ApostalCode);
	
	/**
		Constructor with all vars
		@param AhouseNum integer house number
		@param Astreet string street name
		@param AaptNum string apartment number
		@param Acity string city name
		@param Astate string state name
		@param ApostalCode integer postal code
	*/
	Address(int AhouseNum, string Astreet, string AaptNum, string Acity, string Astate, int ApostalCode);

	/**
		Prints the address with the following format.
		street
		city, state postalCode
	*/
	void print_address() const;

	/**
		tests whether one address comes before another when the addresses are compared by postal code.
		@param givenAdd Address to be compared to
		@return true if the address comes before the given address
	*/
	bool comes_before(Address given) const;


private:
	int houseNum;
	string street;
	string aptNum;
	string city;
	string state;
	int postalCode;
};