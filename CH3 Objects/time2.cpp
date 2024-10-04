// time2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ccc_time.h"
#include <iostream>

using namespace std;

int main()
{
	Time now;
	Time day_end(23,59,59);
	int seconds_left = day_end.seconds_from(now);

	cout << "There are "
		 << seconds_left
		 << " seconds lsft in this day.\n";

	return 0;
}

