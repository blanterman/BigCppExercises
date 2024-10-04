// P12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string user_name;
	cout << "Hello, My name is Hal!\n";
	cout << "What is your name?\n";
	getline(cin, user_name);
	cout << "Hello, " << user_name << ". I am glad to meet you!\n";
	return 0;
}

