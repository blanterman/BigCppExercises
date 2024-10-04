/*	Implement a base class Appointment and derived classes Onetime, Daily, 
Weekly, and Monthly. An appointment has a description (for example, "see the 
dentist"_ and a date and time. Write a virtual function 
occurs_on(int year, int month, int day) that checks whether the appointment 
occurs on that date. For example, for a monthly appointment, you must check 
whether the day of the month matches. Then fill a vector of Appointment* with 
a mixture of appointments. Have the user enter a date and print out all 
appointments that happen on that date.

Bryson Lanterman 20190304
*/

#include "stdafx.h"
#include "P118_Onetime.h"
#include "P118_Daily.h"
#include "P118_Weekly.h"
#include "P118_Monthly.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<Appointment*> apps;
	apps.push_back(new Onetime("Go to beach", 2019, 3, 14, 1700));
	apps.push_back(new Daily("Running 2 miles", 2019, 3, 1, 400));
	apps.push_back(new Weekly("Family Home Evening", 2019, 3, 4, 1800));
	apps.push_back(new Weekly("Church", 2019, 3, 3, 900));
	apps.push_back(new Weekly("Test Handstand time", 2019, 3, 6, 2100));
	apps.push_back(new Monthly("Pay Rent", 2019, 3, 1, 1200));
	apps.push_back(new Monthly("Get haircut", 2019, 3, 15, 1500));
	apps.push_back(new Daily("Drink 64oz. water", 2019, 3, 10, 2000));

	bool cont = true;
	int year;
	int month;
	int day;
	string resp;
	while (cont)
	{
		std::cout << "Please insert Year: ";
		std::cin >> year;
		std::cout << "Please insert Month: ";
		std::cin >> month;
		std::cout << "Please insert Day: ";
		std::cin >> day;

		std::cout << "\n";

		std::cout << "Appointments for " << month << "/" << day << "/" << year << ":\n"
			<< "----------------------------------------\n";
		for (int i = 0; i < apps.size(); i++)
		{
			if (apps[i]->occurs_on(year, month, day))
			{
				std::cout << apps[i]->get_description() << " - at: " << apps[i]->get_time() << "\n";
			}
		}

		std::cout << "\n";

		std::cout << "Find appointments for another date? (y/n)";
		std::cin >> resp;
		if (resp != "y")
		{
			cont = false;
		}
	}
	return 0;
}