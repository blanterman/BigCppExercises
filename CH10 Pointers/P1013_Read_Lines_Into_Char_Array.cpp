/*	Exercise P10.13. Write a progam that reads lines of text and appends them to
a char buffer[1000]. Stop after reading 1,000 characters. As you read in the 
text, replace all newline characters '\n' with '\0' terminators. Establish an 
array char* lines[100], so that the pointers in that array point to the 
beginnings of the lines in the text. Only consider 100 input lines if the input 
has more lines. Then display the lines in reverse order, starting with the last 
input line.

Bryson Lanterman 20190103
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	/* This code was used to create the input file with 5000 lines.
	for (int i = 1; i <= 5000; i++)
	{
		cout << "L: " << i << "\n";
	}
	*/
	
	const int MAXNUMLINES = 100;
	const int MAXNUMCHARS = 1000;
	char buffer[MAXNUMCHARS];
	char* lines[MAXNUMLINES];
	char charIn;
	int numLines = 0;
	int lineLength = 0;

	for (int i = 0; i < MAXNUMCHARS; i++) // stop after MAXNUMCHARS
	{
		if (numLines < MAXNUMLINES)
		{
			if(cin.get(charIn)) // Checks if there is still input.
			{
				if (charIn == '\n') // Checks to see if we have reached a new line character
				{
					buffer[i] = '\0'; // replaces new line character with zero termination character
					lines[numLines] = buffer + i - lineLength; // add the pointer to the first character of the line to lines
					numLines++; // increases the number of lines
					lineLength = 0;
				}
				else // every other character other than a new line character
				{
					buffer[i] = charIn; // puts the character into the buffer
					lineLength++;
				}
			}
		}
	}

	// prints out the lines in reverse order 
	for (int i = numLines; i > 0; i--) // to iterate backwards through pointer array
	{
		char* j = lines[i-1]; // gets the first character pointer of the current line
		while (*j != '\0') // print until a terminator
		{
			cout << *j; // prints out the character
			j++; // increases the pointer
		}
		cout << "\n";
	}
	return 0;
}