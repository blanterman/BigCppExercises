/*	Exercise P9.5. Write a function

vector<int> merge(vector<int> a, vector<int> b)

that merges two arrays, alternating elements from both arrays. If one array is 
sheorter than the other, then alternate as long as you can and then append the 
remaining elements from the longer array. For example, if a is 

1 4 9 16

and b is 

9 7 4 9 11

then merge returns the array 

1 9 4 7 9 4 16 9 11

*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	merges tow arrays, alternating elements from both arrays (static size).
	@param a the first array to merge
	@param b the secont array to merge
	@return an array composed of a and b merged with alternating elements from 
	both
*/
vector<int> merge(vector<int> a, vector<int> b)
{
	vector<int> c(a.size() + b.size()); //Create a vector that can fit a and b.
	
	//put all elements into array while you can alternate
	for (int i = 0; i < min(a.size(), b.size()); i++)
	{
		c[2 * i] = a[i]; //c[0, 2, 4,...]
		c[2 * i + 1] = b[i]; //c[1, 3, 5,...]
	}
	//append left overs from array a or b
	if (a.size() > b.size())
	{
		int indexA = b.size();
		for (int i = b.size() * 2; i < c.size(); i ++)
		{
			c[i] = a[indexA];
			indexA++;
		}
	}
	else if (b.size() > a.size())
	{
		int indexB = a.size();
		for (int i = a.size() * 2; i < c.size(); i ++)
		{
			c[i] = b[indexB];
			indexB++;
		}
	}
	return c;
}

/**
	merges tow arrays, alternating elements from both arrays (dynamic size).
	@param a the first array to merge
	@param b the secont array to merge
	@return an array composed of a and b merged with alternating elements from 
	both
*/
vector<int> merge2(vector<int> a, vector<int> b)
{
	vector<int> c; //Create a vector that can fit a and b.
	
	//put all elements into array while you can alternate
	for (int i = 0; i < min(a.size(), b.size()); i++)
	{
		c.push_back(a[i]); //c[0, 2, 4,...]
		c.push_back(b[i]); //c[1, 3, 5,...]
	}
	//append left overs from array a or b
	if (a.size() > b.size())
	{
		for (int i = b.size(); i < a.size(); i ++)
		{
			c.push_back(a[i]);
		}
	}
	else if (b.size() > a.size())
	{
		for (int i = a.size(); i < b.size(); i ++)
		{
			c.push_back(b[i]);
		}
	}
	return c;
}

/*	Test Harness	*/
int main()
{
	vector<int> a(4);
	a[0] = 1;
	a[1] = 4;
	a[2] = 9;
	a[3] = 16;

	vector<int> b(5);
	b[0] = 9;
	b[1] = 7;
	b[2] = 4;
	b[3] = 9;
	b[4] = 11;

	vector<int> c(9);
	c[0] = 1;
	c[1] = 9;
	c[2] = 4;
	c[3] = 7;
	c[4] = 9;
	c[5] = 4;
	c[6] = 16;
	c[7] = 9;
	c[8] = 11;

	vector<int> d = merge(a, b);
	
	bool matchPassed = true;
	
	bool sizePassed = c.size() == d.size();
	
	if(sizePassed)
	{
		cout << "Size test passed\n";
	}
	else
	{
		cout << "Size test failed\n";
	}

	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] != d[i])
		{
			matchPassed = false;
		}
	}
	
	if(matchPassed)
	{
		cout << "Matching test passed\n";
	}
	else
	{
		cout << "Matching test failed\n";
	}
	

	vector<int> e = merge2(a, b);
	matchPassed = true;
	
	sizePassed = c.size() == e.size();
	
	if(sizePassed)
	{
		cout << "Size test passed\n";
	}
	else
	{
		cout << "Size test failed\n";
	}

	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] != e[i])
		{
			matchPassed = false;
		}
	}
	
	if(matchPassed)
	{
		cout << "Matching test passed\n";
	}
	else
	{
		cout << "Matching test failed\n";
	}
	return 0;
}