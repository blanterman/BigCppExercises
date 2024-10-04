// Replaces a text file's tabs with three spaces

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int col = 0;
	int numSpaces = 0;
	int tab = 3;

	char input;

	while(cin.get(input))
	{
		if(input == '\t')
		{
			numSpaces = -(col % tab) + tab;
			for (int i = 0; i < numSpaces; i++)
			{
				cout << " ";
			}
			col = 0;
		}
		else
		{
			cout << input;
			col++;
		}
	}
	return 0;
}