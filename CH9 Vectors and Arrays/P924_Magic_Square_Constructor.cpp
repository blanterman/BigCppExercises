/*	Exercise P9.24. Implement the following algorithm to construct magic nxn 
squares; it works only if n is odd. Place a 1 in the middle of the bottom row. 
After k has been placed in the (i,j) square, place k+1 into the square to the 
right and down, wrapping around the borders. However, if you reach a square 
that has already been filled, or if you reach the lower right corner, then you 
must move one square up instead. Here is the 5x5 square that you get if you 
follow this method:

11	18	25	2	9
10	12	19	21	3
4	6	13	20	22
23	5	7	14	16
17	24	1	8	15

Write a program  whose input is the number n and whose output is the magic 
square of order n if n is odd.

Bryson Lanterman 20180926
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int ROW_CAPACITY = 99;
const int COL_CAPACITY = 99;

void print_array(const int ms[][COL_CAPACITY], int rowSize, int colSize)
{
	const int WIDTH = 5;
	cout << fixed << setprecision(2);
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			cout << setw(WIDTH) << ms[i][j];
		}
		cout << "\n";
	}
}

int construct_magic_square(int ms[][COL_CAPACITY], int rowSize, int colSize)
{
	int center = ceil(static_cast<double>(rowSize) / 2.0);
	int length = rowSize * colSize;
	int row = rowSize - 1;
	int column = center - 1;
	for (int i = 1; i <= length; i++)
	{
		if (row == (rowSize - 1) && column == (colSize-1)) 
		{
			ms[row][column] = i;
			row--;
		}
		else
		{
			ms[row][column] = i;
			row = (row + 1) % (rowSize);
			column = (column + 1) % (colSize);
			if (ms[row][column] != 0)
			{
				row -= 2;
				column--;
			}
		}
		
		

	}
	return 0;
}



int main()
{
	int rowSize = 0;
	int colSize = 0;
	int magicSquare[ROW_CAPACITY][COL_CAPACITY] = { 0 };
	cout << "Please input an odd size for the magic square\n";
	cin >> rowSize;
	colSize = rowSize;
	construct_magic_square(magicSquare, rowSize, colSize);
	print_array(magicSquare, rowSize, colSize);
}