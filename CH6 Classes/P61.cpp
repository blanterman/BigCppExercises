// P61.cpp : Defines the entry point for the console application.
//

/* This exercise has 3 files:
	P61.cpp
	Person.h
	Person.cpp
	*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int main()
{
	int age = 0;
	string name, ans;
	Person P1, P2;
	cout << "Enter a name: ";
	cin >> name;

	cout << "Do you know the age of the person? (y/n): ";
	cin >> ans;

	if (ans != "n")
	{
		cout << "Enter an age: ";
		cin >> age;
		P1 = Person(name, age);
	}
	else
	{
		P1 = Person(name);
	}

	cout << "Name: " << P1.get_name() << endl;
	cout << "Age: " << P1.get_age() << endl;
	
	cout << "Name: " << P2.get_name() << endl;
	cout << "Age: " << P2.get_age() << endl;
	

	return 0;
}
