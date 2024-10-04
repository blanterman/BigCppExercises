/*	Exercise P10.8. Implement the strncpy functin of the standard library

Bryson Lanterman 20181023
*/

#include "stdafx.h"
#include <iostream>

using namespace std;


/**
	copies a character array to a new location
	@param b new location to copy the character array
	@param a character array to be coppied
	@param maxChars integer maximum number of characters to copy
*/
void strncpy(char b[], char a[], int maxChars)
{
	for (int i = 0; i < maxChars; i++)
	{
		b[i] = a[i];
	}
	b[maxChars] = '\0'; // Adding zero terminator
}

int main()
{
	// Create Character arrays with the proper size when needed.
	const int WORD_SIZE = 29;
	char a[] = "SuperMicroGeniDupliFabricator"; // Best Invention Ever aka "Mini-me Maker"
	char b[WORD_SIZE + 1];

	// Copy a into b
	strncpy(b, a, WORD_SIZE);

	// Test that the copy worked
	bool copy = true;
	for (int i = 0; i < WORD_SIZE; i++)
	{
		if (a[i] != b[i])
		{
			copy = false;
		}
	}

	// Print out results
	if (copy)
	{
		cout << "Pass\n";
	}
	else
	{
		cout << "Fail\n";
	}
	return 0;
}