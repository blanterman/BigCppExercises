// time1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ccc_time.h"

#include <iostream>
using namespace std;


int main()
{
	Time wake_up(7, 0, 0);
	wake_up.add_seconds(1000);
	cout << wake_up.get_hours()
		 << ":" <<wake_up.get_minutes()
		 << ":" <<wake_up.get_seconds() << "\n";
	return 0;
}

