/*	Ecercise P10.7. Write a function that reverses the values of an array of 
floating-point data:

void reverse(double a[], int a_size)

In the function, use two pointer variables, and not integer indexes, to 
traverse the array elements


Bryson Lanterman 20181022
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	reverses the values of an array of floating point data
	@param a an array of floating point data
	@param a_size integer size of the array
*/
void reverse (double a[], int a_size)
{
	double* beg = a;				//Pointer to the first element
	double* end = a + a_size - 1;	//Pointer to the last element

	double buffer = 0;				//Holding place for first element

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
	prints out an array of floating point data
	@param a an array of floating point data
	@param a_size integer size of the array
*/

void printArr(double a[], int a_size)
{
	double* curr = a;
	while(curr < a + a_size)
	{
		cout << *curr << "   ";
		curr++;
	}
	cout << "\n";
}

int main()
{
	double evenArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double oddArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	reverse(evenArr, 10);
	reverse(oddArr, 9);

	printArr(evenArr, 10);
	printArr(oddArr, 9);
	return 0;
}