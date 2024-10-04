/*	Exercise P10.15. the preceding problem demonstrated how to use the string 
and vector classes to implement resizable arrays. In this exercise, you should 
implement that capability manually. Allocate a buffer of 1,000 characters from 
the heap (new char[1000]). Whenever the buffer fills up, allocate a buffer of 
twice the size, copy the buffer contents, and delete the old buffer. Do the 
same for the array of char* pointers - start with a new char*[100] and keept 
doubling the size.

Bryson Lanterman 20190118
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
	int charCapacity = 1000;
	int linesCapacity = 100;
	char* buffer = new char[charCapacity];
	char** lines = new char*[linesCapacity];
	char charIn;
	int numLines = 0;
	int numChars = 0;
	int lineLength = 0;

	while(cin.get(charIn)) // Checks if there is still input.
	{
		if (numChars == charCapacity)
		{
			int biggerCharCapacity = 2 * charCapacity;
			char* biggerBuffer = new char[biggerCharCapacity];
			for (int i = 0; i < charCapacity; i++)
			{
				biggerBuffer[i] = buffer[i];
			}
			delete buffer;
			buffer = biggerBuffer;
			charCapacity = biggerCharCapacity;
		}
		if (charIn == '\n') // Checks to see if we have reached a new line character
		{
			buffer[numChars] = '\0'; // replaces new line character with zero termination character
		}
		else // every other character other than a new line character
		{
			buffer[numChars] = charIn; // puts the character into the buffer
		}
		numChars++;
	}
	for (int i = 0; i < numChars; i++)
	{
		if (numLines == linesCapacity)
		{
			int biggerLinesCapacity = 2 * linesCapacity;
			char** biggerLines = new char*[biggerLinesCapacity];
			for (int j = 0; j < linesCapacity; j++)
			{
				biggerLines[j] = lines[j];
			}
			delete lines;
			lines = biggerLines;
			linesCapacity = biggerLinesCapacity;
		}
		if (buffer[i] == '\0') // Checks to see if we have reached a zero terminator character
		{
			lines[numLines] = buffer + i - lineLength; // add the pointer to the first character of the line to lines
			numLines++; // increases the number of lines
			lineLength = 0;
		}
		else
		{
			lineLength++;
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

	delete buffer;
	delete lines;

	return 0;
}