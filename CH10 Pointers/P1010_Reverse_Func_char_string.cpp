/*	Exercise P10.10. Write a function

voide reverse(char s[])

that reverses a character string. For example, "Harry" becomes "yrraH".

Bryson Lanterman 20181104
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	reverses a character string
	@param s character string
*/
void reverse(char s[])
{
	int s_size = 0;
	int i = 0;
	while(s[i] != '\0')
	{
		s_size++;
		i++;
	}

	char* beg = s;				//Pointer to the first element
	char* end = s + s_size - 1;	//Pointer to the last element

	char buffer = '\0';				//Holding place for first element

	// Swap the elements and then move the pointers closer together
	// Repeat until the pointers cross or are equal.
	while (beg < end)
	{
		// Swap the two elements
		buffer = *beg;
		*beg = *end;
		*end = buffer;

		// Move the pointers closer together
		beg++;
		end--;
	}
}

/**
	prints out a character string
	@param a a character string

*/
void printStr(char a[])
{
	char* curr = a;
	while(*curr != '\0')
	{
		cout << *curr << "";
		curr++;
	}
	cout << "\n";
}

int main()
{
	char evenstr[] = "Harry";
	char oddstr[] = "Bryson";

	reverse(evenstr);
	reverse(oddstr);

	printStr(evenstr);
	printStr(oddstr);
	return 0;
}
