// P62.cpp : Defines the entry point for the console application.
// Tests the mutators and accessors of the PEmployee class

#include "stdafx.h"
#include <iostream>
#include "PEmployee.h"


using namespace std;

int main()
{
	string name;
	double salary;

	cout << "Name: ";
	cin >> name;
	cout << "starting salary: ";
	cin >> salary;

	PEmployee p1;
	PEmployee p3("Bryson", 100000.0);
	PEmployee p2(name, salary);

	cout << "Employee name: " << p1.get_name() << endl;
	cout << "Employee salary: " << p1.get_salary() << endl;
	cout << "Employee name: " << p2.get_name() << endl;
	cout << "Employee salary: " << p2.get_salary() << endl;
	cout << "Employee name: " << p3.get_name() << endl;
	cout << "Employee salary: " << p3.get_salary() << endl;

	cout << "Enter new salary for " << p1.get_name() << ": ";
	cin >> salary;
	p1.set_salary(salary);
	cout << "Enter new salary for " << p2.get_name() << ": ";
	cin >> salary;
	p2.set_salary(salary);
	cout << "Enter new salary for " << p3.get_name() << ": ";
	cin >> salary;
	p3.set_salary(salary);

	cout << "Employee name: " << p1.get_name() << endl;
	cout << "Employee salary: " << p1.get_salary() << endl;
	cout << "Employee name: " << p2.get_name() << endl;
	cout << "Employee salary: " << p2.get_salary() << endl;
	cout << "Employee name: " << p3.get_name() << endl;
	cout << "Employee salary: " << p3.get_salary() << endl;

    return 0;
}

