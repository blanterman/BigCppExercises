/*	Exercise P10.14. The preceding program is limited by the fact that it can 
only handle inpus of 1,000 characters or 100 lines. Remove this limitation as 
follows. Concatenate the input in one long string object. Use the c_str method
to obtain a char* into the string's character buffer. Establish the offsets of 
the beginnings of the lines as a vector<int>.


Bryson Lanterman 20190107
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	/* This code was used to create the input file with 5000 lines.
	for (int i = 1; i <= 5000; i++)
	{
		cout << "L: " << i << "\n";
	}
	*/
	
	string buffer;
	vector<int> lines;
	char charIn;
	int lineLength = 0;
	int charsProcessed = 0;
	int numLines = 0;


	while (cin.get(charIn)) // Checks if there is still input.
	{
		if (charIn == '\n') // Checks to see if we have reached a new line character
		{
			buffer.push_back('\0'); // replaces new line character with zero termination character
			lines.push_back (charsProcessed - lineLength); // add the offset of the first character of the line to lines
			numLines++; // increases the number of lines
			lineLength = 0;
		}
		else // every other character other than a new line character
		{
			buffer.push_back(charIn); // puts the character into the buffer
			lineLength++;
		}
		charsProcessed++;
	}



	// prints out the lines in reverse order 
	for (int i = numLines; i > 0; i--) // to iterate backwards through pointer array
	{
		const char* j = buffer.c_str() + lines[i-1]; // gets the first character pointer of the current line
		while (*j != '\0') // print until a terminator
		{
			cout << *j; // prints out the character
			j++; // increases the pointer
		}
		cout << "\n";
	}
	return 0;
}