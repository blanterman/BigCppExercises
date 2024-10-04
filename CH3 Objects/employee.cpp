// employee.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ccc_empl.h"

using namespace std;

int main()
{
	Employee harry("Hacker, Harry", 45000.00);

	double new_salary = harry.get_salary() + 3000;
	harry.set_salary(new_salary);

	cout << "Name: " << harry.get_name() << "\n";
	cout << "Salary: " << harry.get_salary() << "\n";

	return 0;
}

