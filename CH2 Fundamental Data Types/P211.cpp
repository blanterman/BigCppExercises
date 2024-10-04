// P211.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string drive = "", path = "", file_name = "", ext = "";
	cout << "Drive Letter: ";
	cin >> drive;
	cout << "Path: ";
	cin >> path;
	cout << "File name: ";
	cin >> file_name;
	cout << "Extension: ";
	cin >> ext;

	cout << drive << ":" << path << "\\" << file_name << "." << ext << "\n";
	return 0;
}

