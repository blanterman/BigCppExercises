// P11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string user_name;
	cout << "Hello, my name is Hal!\n";
	cout << "What would you like me to do?\n";
	getline(cin,user_name);
	cout << "I am sorry, I cannot do that.\n";

	return 0;
}

