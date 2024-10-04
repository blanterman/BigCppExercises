// P416.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ccc_empl.h"
#include <iostream>
#include <string>

using namespace std;

const double FT_HOURS = 40;
const double OT_FACTOR = 1.5;

int main()
{
	string name;
	double salary = 0, hours = 0, pay = 0, ot_salary = 0, ot_pay = 0, ot_hours = 0, ft_pay = 0;

	cout << "Name of Employee: ";
	getline(cin, name);

	cout << "Hourly wage of employee: ";
	cin >> salary;

	Employee emp1(name, salary);

	cout << "How many hours did the employee work in the last week?";
	cin >> hours;

	ot_hours = hours - FT_HOURS;

	if (ot_hours > 0)
	{
		ft_pay = FT_HOURS * emp1.get_salary();
		ot_salary = OT_FACTOR * emp1.get_salary();
		ot_pay = ot_hours * ot_salary;
		pay = ft_pay + ot_pay;
	}
	else
	{
		pay = hours * emp1.get_salary();
	}

	cout << "Paycheck for " << emp1.get_name() << " is: " << pay << "\n";

	return 0;
}

