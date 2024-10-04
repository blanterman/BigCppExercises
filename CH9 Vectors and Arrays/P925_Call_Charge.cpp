#include "stdafx.h"
#include "P925_Call.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int ROW_CAPACITY = 100;
const int COL_CAPACITY = 100;

/**
	returns the index number of the element name in the given vector
	@param v a vector of strings
	@param element a string
	@return integer index of the element string in the vector
*/
int element_to_index(const vector<string>& v, string element)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == element)
		{
			return i;
		}
	}
	return -1;
}

/**
	Populates a row in a 2D array with the data from a 1D row array
*/
void populate_row(double Arr2D[][COL_CAPACITY], int row, const double rowvals[], int cols)
{
	for (int i = 0; i < cols; i++)
	{
		Arr2D[row][i] = rowvals[i];
	}
}

/**
	Prints a table of data
	@param the table to print
	@param rows the number of rows of the table
	@param cols the number of columns of the table
*/
void print_table(const double table[][COL_CAPACITY], int rows, int cols)
{
	const int WIDTH = 10;
	cout << fixed << setprecision(2);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(WIDTH) << table[i][j];
		}
		cout << "\n";
	}
}


int main()
{
	// Cities that can be called.
	vector<string> toCity(9);
	toCity[0] = "Sudbury";
	toCity[1] = "Framingham";
	toCity[2] = "Lowell";
	toCity[3] = "Brockton";
	toCity[4] = "Worcester";
	toCity[5] = "Rockport";
	toCity[6] = "Fall River";
	toCity[7] = "Falmouth";
	toCity[8] = "Hyannis";


	// Call rates to the cities in toCity vector. Rows of table defined
	double rrow0[COL_CAPACITY] = { 0.19, 0.09, 0.12, 0.05, 0.07, 0.03 };
	double rrow1[COL_CAPACITY] = { 0.26, 0.12, 0.16, 0.07, 0.10, 0.04 };
	double rrow2[COL_CAPACITY] = { 0.32, 0.14, 0.20, 0.09, 0.12, 0.05 };
	double rrow3[COL_CAPACITY] = { 0.38, 0.15, 0.24, 0.09, 0.15, 0.06 };
	double rrow4[COL_CAPACITY] = { 0.43, 0.17, 0.27, 0.11, 0.17, 0.06 };
	double rrow5[COL_CAPACITY] = { 0.48, 0.19, 0.31, 0.12, 0.19, 0.07 };
	double rrow6[COL_CAPACITY] = { 0.51, 0.20, 0.33, 0.13, 0.20, 0.08 };
	double rrow7[COL_CAPACITY] = { 0.53, 0.21, 0.34, 0.13, 0.21, 0.08 };
	double rrow8[COL_CAPACITY] = { 0.54, 0.22, 0.35, 0.14, 0.21, 0.08 };
	// Call rates table created
	double rates[ROW_CAPACITY][COL_CAPACITY];

	// Call rates table populated row by row
	int RRowSize = 9;
	int RColSize = 6;
	populate_row(rates, 0, rrow0, RColSize);
	populate_row(rates, 1, rrow1, RColSize);
	populate_row(rates, 2, rrow2, RColSize);
	populate_row(rates, 3, rrow3, RColSize);
	populate_row(rates, 4, rrow4, RColSize);
	populate_row(rates, 5, rrow5, RColSize);
	populate_row(rates, 6, rrow6, RColSize);
	populate_row(rates, 7, rrow7, RColSize);
	populate_row(rates, 8, rrow8, RColSize);

	// Days of the week when calls can be made
	vector<string> days(7);
	days[0] = "Monday";
	days[1] = "Tuesday";
	days[2] = "Wednesday";
	days[3] = "Thursday";
	days[4] = "Friday";
	days[5] = "Saturday";
	days[6] = "Sunday";

	// Rates fall into 3 categories based on day and time
	// according to the table below. Here rows are defined.
	double rateCategoryRow0[] = { 0, 0, 0, 0, 0, 2, 2 };
	double rateCategoryRow1[] = { 1, 1, 1, 1, 1, 2, 1 };
	double rateCategoryRow2[] = { 2, 2, 2, 2, 2, 2, 2 };
	// Rate category table is created
	double rateCategories[ROW_CAPACITY][COL_CAPACITY];

	// Rate category table is populated row by row.
	int RCRowSize = 3;
	int RCColSize = 7;
	populate_row(rateCategories, 0, rateCategoryRow0, RCColSize);
	populate_row(rateCategories, 1, rateCategoryRow1, RCColSize);
	populate_row(rateCategories, 2, rateCategoryRow2, RCColSize);

	// Tables printed out for debugging
	print_table(rates, RRowSize, RColSize);
	print_table(rateCategories, RCRowSize, RCColSize);

	// Call information is gotten from user or from file
	string dest;
	string time;
	string day;
	string length;

	cout << "dest: ";
	getline(cin, dest);
	cout << "time: ";
	getline(cin, time);
	cout << "length: ";
	getline(cin, length);
	int len = stoi(length);
	cout << "day: ";
	getline(cin, day);

	// Call object created
	P925_Call callOne(dest, time, len, day);

	/*
	Call rates will need to be looked up in the above rates table.
	the M value (Location) will depend only on the location, the 
	N value (rate category) will depend on the day and time
	*/
	// M value of the rates table computed by destination entered.
	int rateM = element_to_index(toCity, callOne.get_destination());
	
	// Category table N value computed by day entered.
	int categoryN = element_to_index(days, callOne.get_day());

	// Category table M value computed by start time.
	double timedec = callOne.get_startTime();
	double lendec = callOne.get_length();
	int categoryM = -1;
	bool over = false;
	double overage = 0.0;
	if(8.0 <= timedec && timedec < 17.0)
	{
		categoryM = 0;
		if ((timedec + lendec) >= 17.0)
		{
			over = true;
			overage = lendec - (17.0 - timedec);
		}
	}
	if(17.0 <= timedec && timedec < 23.0)
	{
		categoryM = 1;
		if ((timedec + lendec) >= 23.0)
		{
			over = true;
			overage = lendec - (23.0 - timedec);
		}
	}
	if((23.0 <= timedec && timedec < 24.0) || (0.0 <= timedec && timedec < 8.0))
	{
		categoryM = 2;
		if ((timedec + lendec - 24.0) >= 8.0)
		{
			over = true;
			overage = 8.0 - (timedec + lendec - 24.0);
		}
	}

	// N value of the rated table retrieved based on category information
	int rateN = static_cast<int>(rateCategories[categoryM][categoryN]) * 2;

	// rates[rateM][rateN] is the rate of the first minute
	// rates[rateM][rateN + 1] is the rate of each additional minute
	cout << timedec << "\n"
		<< lendec << "\n"
		<< "First Minute for: " << rates[rateM][rateN] << "\n"
		<< "Each Additional minute: " << rates[rateM][rateN + 1] << "\n";

	double firstMinRate1 = rates[rateM][rateN];
	double additionalMinRate1 = rates[rateM][rateN + 1];

	double firstMinRate2 = rates[rateM][(rateN + 2) % 6];
	double additionalMinRate2 = rates[rateM][(rateN + 3) % 6];

	double cost = firstMinRate1 + additionalMinRate1 * ((callOne.get_length() - overage) * 60.0 - 1);
	if (over)
	{
		cost += firstMinRate2 + additionalMinRate2 * (overage * 60.0 - 1);
	}

	cout << "\n" << "Call Costs: " << cost << "\n"
		<< "overspill: " << over << "\n";
	return 0;
}