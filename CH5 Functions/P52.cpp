// P52.cpp : Defines the entry point for the console application.
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

int main()
{
	int u = 2;
	int v = 3;
	int w = 4;
	int x = 1;

	cout << "Before: (u,v) = (" << u << ", " << v << ")\n"; 
	cout << "Before: (w,x) = (" << w << ", " << x << ")\n"; 

	sort2(u, v);
	sort2(w, x);

	cout << "After: (u,v) = (" << u << ", " << v << ")\n"; 
	cout << "After: (w,x) = (" << w << ", " << x << ")\n"; 

	return 0;
}

