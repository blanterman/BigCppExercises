#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int factoree = 0;
	int count = 0;

	cout << "Please enter an integer: ";
	cin >> factoree;

	while(factoree != 1)
	{
		for(int i = 2; i <= factoree; i++)
		{
			if(factoree % i == 0)
			{
				count++;
				cout << i << "\n";
				factoree /= i;
				i = 1;
			}
		}
	}

	return 0;
}