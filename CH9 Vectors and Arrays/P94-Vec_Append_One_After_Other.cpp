/* Exercise P.4. Write a function

vector<int> append(vector<int> a, vector<int> b)

that appends one vector after another. For example, if a is

1 4 9 16

and b is

9 7 4 9 11

then append returns the vector 

1 4 9 16 9 7 4 9 11
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	appends vector b after vector a to a new vector using a static vector sizing
	method
	@param a vector of ints
	@param b vector of ints
	@raturn a vector of ints with b appended to a
*/
vector<int> append(vector<int> a, vector<int> b)
{
	int sizeA = a.size();
	int sizeB = b.size();
	vector<int> c(sizeA + sizeB);
	for (int i = 0; i < sizeA; i++)
	{
		c[i] = a[i];
	}
	int j = 0;
	for (int i = a.size(); i < c.size(); i++)
	{
		c[i] = b[j];
		j++;
	}
	return c;
}
/**
	appends vector b after vector a to a new vector using a dynamic vector sizing
	method
	@param a vector of ints
	@param b vector of ints
	@raturn a vector of ints with b appended to a
*/
vector<int> append2(vector<int> a, vector<int> b)
{
	vector<int> c;
	for (int i = 0; i < a.size(); i++)
	{
		c.push_back(a[i]);
	}
	for (int i = 0; i < b.size(); i++)
	{
		c.push_back(b[i]);
	}
	return c;
}

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
	c[1] = 4;
	c[2] = 9;
	c[3] = 16;
	c[4] = 9;
	c[5] = 7;
	c[6] = 4;
	c[7] = 9;
	c[8] = 11;
	
	// Test static function method
	vector<int> d = append(a,b);
	bool flag = true;
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] != d[i])
			flag = false;
	}
	if (flag == false)
		cout << "Static method failed\n";
	else
		cout << "Static method passed\n";

	// Test dynamic function method
	vector<int> e = append2(a,b);
	bool flag2 = true;
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] != e[i])
			flag2 = false;
	}
	if (flag2 == false)
		cout << "Dynamic method failed\n";
	else
		cout << "Dynamic method passed\n";

	return 0;
}