/*	Exercise P10.11. Using the strncpy and strncat functions, implement a 
function 

void concat(const char a[], const char b[], char result[], 
	int result_maxlength)

that concatenates the strings a and b to the buffer result. Be sure not to 
overrun the result. It can hold result_maxlength characters, not counting the
'/0' terminator. (That is, the buffer has result_maxlength + 1 bytes 
available.) Be sure to provide a '/0' terminator.

Bryson Lanterman 20181217
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	concatenates the strings a and b to the buffer result
	@param a the first character string
	@param b the second character string to be concatenated to the first
	@param result the character string that will hold the concatenated string
	@param result_maxlength
*/
void concat2(const char a[], const char b[], char result[], int result_maxlength)
{
	int i = 0;
	int j = 0;
	while(*(a + i) != '\0' && result_maxlength > (i + j))
	{
		*(result + i) = *(a + i);
		i++;
	}
	while(*(b + j) != '\0' && result_maxlength > (i + j))
	{
		*(result + j + i) = *(b + j);
		j++;
	}
	*(result + i + j) = '\0';
}

/**
	concatenates the strings a and b to the buffer result
	@param a the first character string
	@param b the second character string to be concatenated to the first
	@param result the character string that will hold the concatenated string
	@param result_maxlength
*/
void concat(const char a[], const char b[], char result[], int result_maxlength)
{
	strncpy(result, a, result_maxlength);
	strncat(result, b, result_maxlength);
}

int main()
{
	char a[] = "Bryson";
	char b[] = " and Shannon";
	char c[sizeof(a) + sizeof(b)];
	concat(a, b, c, sizeof(a) + sizeof(b));
	cout << c << "\n";
	return 0;
}