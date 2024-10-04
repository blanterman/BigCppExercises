// P317.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ccc_time.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string resp, sent, remainder;
	cout << "Would you like to time your typing? (y/n) ";
	cin >> resp;
	getline(cin, remainder);
	if(resp == "n")
		return 0;
	else
	{
		int tbtw = 0;
		Time t1;
		cout << "Type: \n"
			 << "The quick brown fox jumps over the lazy dog \n";
		getline(cin, sent);
		Time t2;
		tbtw = t2.seconds_from(t1);
		cout << "It took you: " << tbtw << " seconds." << endl;
	}
	return 0;
}

