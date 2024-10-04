#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int fold1 = 1;
	int fold2 = 1;
	int numfib = 0;
	
	cout << "How many fibonacci numbers would you like? (Must be greater than or equal to 2) ";
	cin >> numfib;

	cout << fold1 << "\n" << fold2 << "\n";

	for (int i = 2; i < numfib; i++)
	{
		int fnew = fold1 + fold2;
		cout << fnew << "\n";
		fold1 = fold2;
		fold2 = fnew;
	}

	return 0;
}