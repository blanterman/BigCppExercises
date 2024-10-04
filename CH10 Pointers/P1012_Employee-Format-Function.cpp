#include "stdafx.h"
#include <iostream>
#include "P1012_Employee.h"

using namespace std;

int main()
{
	Employee emp1("Lanterman, Bryson", 100000.50);
	char buffer[100];
	emp1.format(buffer, sizeof(buffer));
	cout << buffer << endl;
	return 0;
}