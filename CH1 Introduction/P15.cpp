// P15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Declare Variables
	string user_name;
	int name_len;

	// Prompts the user to enter his/her name and assigns variables
	cout << "What is your name?\n";
	getline(cin, user_name);
	name_len = user_name.length();

	// Constructs the box and puts the name in it
	for (int i = 0; i < name_len + 4; i++)
		cout << "_";	
	cout << "\n| " << user_name << " |\n";
	for (int i = 0; i < name_len + 4; i++)
		cout << "-";
	cout << "\n";
	
	return 0;
}

