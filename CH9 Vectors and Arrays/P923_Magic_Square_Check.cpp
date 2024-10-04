/*	Exercise P9.23. Magic Squares. An n x n matrix that is filled with the 
numbers 1,2,3,..,n^2 is a magic square if the sum of the elements in each row, 
in each column, and in the two diagonals in the same value. For example,

16	3	2	13
5	10	11	8
9	6	7	12
4	15	14	1

Write a program that reads in n^2 values from the keyboard and tests whether 
they form a magic square when put into array form. You need to test three 
features:

1. Did the user enter n^2 number for some n?
2. Does each of the numbers 1, 2, ..., n^2 occur uxactly once in the user 
input?
3. When the numbers are put into a square, are the sums of the rows, columns, 
and diagonals equal to each other?

Hint: first read the number into a vector. If the size of the vector is a 
square, test whether all numbers between 1 and n are present. Then fill the 
numbers into a matrix and compute the row, column, and diagonal sums.

*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

const int ROW_CAPACITY = 100;
const int COL_CAPACITY = 100;

/**
	checks that the size of a vector is n^2 for some n
	@param sizeIn integer
	@return squareSize boolean true if size is square
*/
bool is_square(int sizeIn)
{
	double rootSize = sqrt(static_cast<double>(sizeIn));
	double fractPart = rootSize - floor(rootSize);
	return fractPart == 0.0;
}

/**
	checks that a vector of size n has the elements 1 to n
	@param v vector of n elements
	@return true if vector has elements 1 to n
*/
bool proper_contents(const vector<int>& v)
{
	bool contentsGood = true; // to get in the loop
	int i = 1;

	// Use a while loop so that the flag can be used to exit the loop.
	while(contentsGood && i <= v.size())
	{
		contentsGood = false; //reset the flag
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == i)
			{
				contentsGood = true; // sets the flag to go to the next iteration
			}
		}
		i++;
	}

	// Will only be true if all values were found and the last value was reached.
	return contentsGood;
}


/**
	populates a square array with the values in a vector
	@param square 2D array of 100 x 100 elements possible.
	@param v vector with the values to be put into the array
	@param rows number of rows to be filled
	@param cols number of columns to be filled
*/
void populate_square(int square[][COL_CAPACITY], const vector<int>& v, int rows, int cols)
{
	int index = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			square[i][j] = v[index];
			index++;
		}
	}
}

void print_square(const int square[][COL_CAPACITY], int rows, int cols)
{
	
	const int WIDTH = 10;
	cout << fixed << setprecision(2);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(WIDTH) << square[i][j];
		}
		cout << "\n";
	}
}

bool is_magic(const int square[][COL_CAPACITY], int rows, int cols)
{
	int horizontal = 0;
	for(int i = 0; i < cols; i++)
	{
		horizontal += square[0][i];
	}
	
	for(int i = 1; i < rows; i++)
	{
		int horizontalNew = 0;
		for(int j = 0; j < cols; j++)
		{
			horizontalNew += square[i][j];
		}
		if(horizontalNew != horizontal)
		{
			return false;
		}
	}

	int vertical = 0;
	for(int i = 0; i < rows; i++)
	{
		vertical += square[i][0];
	}
	
	if(vertical != horizontal)
	{
		return false;
	}

	for(int i = 1; i < cols; i++)
	{
		int verticalNew = 0;
		for(int j = 0; j < rows; j++)
		{
			verticalNew += square[j][i];
		}
		if(verticalNew != vertical)
		{
			return false;
		}
	}

	int diagonal = 0;
	for(int i = 0; i < rows; i++)
	{
		diagonal += square[i][i];
	}

	if(diagonal != horizontal)
	{
		return false;
	}

	int diagonalNew = 0;
	for(int i = 0; i < rows; i++)
	{
		int j = cols - 1;
		diagonalNew += square[i][j];
		j--;
	}
	if(diagonal != diagonalNew)
	{
		return false;
	}

	return true;

	
}

int main()
{
	int magicSquare[ROW_CAPACITY][COL_CAPACITY];

	int userIn = 0;
	int rowSize = 0;
	int colSize = 0;
	vector<int> belt;
	while (cin >> userIn)
	{
		belt.push_back(userIn);
	}
	if (is_square(belt.size()))
	{
		if(proper_contents(belt))
		{
			rowSize = (int)sqrt(static_cast<double>(belt.size()));
			colSize = rowSize;
			populate_square(magicSquare, belt, rowSize, colSize);
			print_square(magicSquare, rowSize, colSize);
			if(is_magic(magicSquare, rowSize, colSize))
			{
				cout << "winner winner chicken dinner\n";
			}
			else
			{
				cout << "No dice\n";
			}
		}
		else
		{
			cout << "bad elements\n";
		}
	}
	else
	{
		cout << "not hip enough\n";
	}
	return 0;
}