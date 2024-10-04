// P53.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


/**
	Takes two integers and puts them into ascending order
	@param a first integer
	@param b second integer
*/

void sort2(int& a, int& b)
{
	int temp = 0;
	if (b <= a)
	{
		temp = b;
		b = a;
		a = temp;
	}
}

/**
	Takes three integers and puts them into ascending order
	@param a first integer
	@param b second integer
	@param c third integer
*/
void sort3(int& a, int& b, int& c)
{
	//bubblesort first pass
	sort2(b, c);
	sort2(a, b);
	//bubblesort second pass
	sort2(b, c);
	sort2(a, b);
}

int main()
{
	int u = 2;
	int v = 3;
	int w = 4;
	int x = 4;
	int y = 2;
	int z = 3;
	
	cout << "Before: (u,v,w) = (" << u << ", " << v << ", " << w << ")\n"; 
	cout << "Before: (x,y,z) = (" << x << ", " << y << ", " << z << ")\n"; 

	sort3(u, v, w);
	sort3(x, y, z);

	cout << "After: (u,v,w) = (" << u << ", " << v << ", " << w << ")\n";
	cout << "After: (x,y,z) = (" << x << ", " << y << ", " << z << ")\n";

	return 0;
}


