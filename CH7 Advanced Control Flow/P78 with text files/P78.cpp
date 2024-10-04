#include "stdafx.h"
#include <iostream>

using namespace std;

/*
	Determines if a number is prime by finding all the factors ovr one and counting them. 
	If the count is 1 then the number is prime
*/
bool prime_check(long long maybe_prime)
{
	long long factoree = maybe_prime;
	long long count = 0;

	while(factoree != 1)
	{
		for(long long i = 2; i <= factoree; i++)
		{
			if(factoree % i == 0)
			{
				count++;
				factoree /= i;
				i = 1;
			}
		}
	}
	return (count == 1);
}

int main()
{
	long long upper_bound = 0;
	cout << "Please enter an integer: ";
	cin >> upper_bound;

	for(long long i = 2; i <= upper_bound; i++)
	{
		if(prime_check(i))
		{
			cout << i << "\n";
		}
	}	

	return 0;
}