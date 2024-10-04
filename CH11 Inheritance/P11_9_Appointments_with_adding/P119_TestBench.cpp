/*	P11.8.Implement a base class Appointment and derived classes Onetime, Daily, 
Weekly, and Monthly. An appointment has a description (for example, "see the 
dentist"_ and a date and time. Write a virtual function 
occurs_on(int year, int month, int day) that checks whether the appointment 
occurs on that date. For example, for a monthly appointment, you must check 
whether the day of the month matches. Then fill a vector of Appointment* with 
a mixture of appointments. Have the user enter a date and print out all 
appointments that happen on that date.

Bryson Lanterman 20190304

	Exercise P11.9. Improve the appointment book program of the preceding 
exercise. Give the user the option to add new appointments. The user must 
specify the type of the appointment, the description, and the date and time.

Bryson Lanterman 20190306
*/

#include "stdafx.h"
#include "P119_Onetime.h"
#include "P119_Daily.h"
#include "P119_Weekly.h"
#include "P119_Monthly.h"
#include <iostream>
#include <vector>

int main()
{
	// Adds some appointment to a vector of appointment pointers
	std::vector<Appointment*> apps;
	apps.push_back(new Onetime("Go to beach", 2019, 3, 14, 1700));
	apps.push_back(new Daily("Running 2 miles", 2019, 3, 1, 400));
	apps.push_back(new Weekly("Family Home Evening", 2019, 3, 4, 1800));
	apps.push_back(new Weekly("Church", 2019, 3, 3, 900));
	apps.push_back(new Weekly("Test Handstand time", 2019, 3, 6, 2100));
	apps.push_back(new Monthly("Pay Rent", 2019, 3, 1, 1200));
	apps.push_back(new Monthly("Get haircut", 2019, 3, 15, 1500));
	apps.push_back(new Daily("Drink 64oz. water", 2019, 3, 10, 2000));

	// Initialize some variables
	bool cont = true;
	bool enterNew = false;
	bool readApp = false;
	int year;
	int month;
	int day;
	int time;
	string resp;
	string desc;
	string type;
	string remainder;
	bool valid = false;

	while (cont)
	{
		// Ask the user if they would like to add an appointment or 
		std::cout << "What would you like to do?\n"
			<< "(a)  Add appointment \n"
			<< "(r)  Read appointments by date \n"
			<< "(q)  Quit\n";
		std::getline(std::cin, resp);

		// Process response from user
		if (resp == "a")
		{
			enterNew = true;
		}
		else if (resp == "r")
		{
			readApp = true;
		}
		else if (resp == "q")
		{
			cont = false;
		}
		else
		{
			std::cout << "Please make a proper entry.";
		}


		std::cout << "\n";

		// Add as many appointments as the user wants
		while (enterNew)
		{
			while (!valid)
			{
				// Get the appointment type from the user
				std::cout << "New Appointment Type: ((m)onthly, (w)eekly, (d)aily, or (o)netime) ";
				std::getline(std::cin, type);

				// Make sure the type input from the user is a valid option
				if (type == "m" || type == "w" || type == "d" || type == "o")
				{
					valid = true;
				}
				else
				{
					std::cout << "Please insert a valid type. \n\n";
				}
			}

			// Get the rest of the information about the appointment from the user
			std::cout << "New Appointment Description: ";
			std::getline(std::cin, desc);
			std::cout << "New Appointment Year: ";
			std::cin >> year;
			std::cout << "New Appointment Month: ";
			std::cin >> month;
			std::cout << "New Appointment Day: ";
			std::cin >> day;
			std::cout << "New Appointment Time: (Military format) ";
			std::cin >> time;

			// Add the appropriate type of appointment to the appointment book
			if (type == "m")
			{
				apps.push_back(new Monthly(desc, year, month, day, time));
			}
			if (type == "w")
			{
				apps.push_back(new Weekly(desc, year, month, day, time));
			}
			if (type == "d")
			{
				apps.push_back(new Daily(desc, year, month, day, time));
			}
			if (type == "o")
			{
				apps.push_back(new Onetime(desc, year, month, day, time));
			}

			// Since mixing of cin >> and getline() we need to get the remainder of the line
			std::getline(std::cin, remainder); // gets remainder of line

			// Prompts the user to add another appointment
			std::cout << "Would you like to add another appointment? (y/n)";
			std::getline(std::cin, resp);

			// Processes input from user
			if (resp != "y")
			{
				enterNew = false;
			}
			else
			{
				valid = false;
			}
		}


		while (readApp)
		{
			// Asks the user for date on which to find appointments
			std::cout << "------- Accessing appointments -------\n";
			std::cout << "Please insert Year: ";
			std::cin >> year;
			std::cout << "Please insert Month: ";
			std::cin >> month;
			std::cout << "Please insert Day: ";
			std::cin >> day;

			std::cout << "\n";

			// Prints out header
			std::cout << "Appointments for " << month << "/" << day << "/" << year << ":\n"
				<< "----------------------------------------\n";

			// Cycles through all appointments and prints out the ones that are on users date
			for (int i = 0; i < apps.size(); i++)
			{
				if (apps[i]->occurs_on(year, month, day))
				{
					std::cout << apps[i]->get_description() << " - at: " << apps[i]->get_time() << "\n";
				}
			}

			std::cout << "\n";

			// Since mixing of cin >> and getline() we need to get the remainder of the line
			std::getline(std::cin, remainder); // gets remainder of line

			// Asks the user if they want to find appointments on another date
			std::cout << "Find appointments for another date? (y/n)";
			std::getline(std::cin, resp);

			// Processes input from user
			if (resp != "y")
			{
				readApp = false;
			}
		}
	}
	return 0;
}