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
#include "P118_Weekly.h"
#include "day_date.h"

Weekly::Weekly()
	:Appointment()
{

}

Weekly::Weekly(string desc, int year, int month, int day, int time)
	:Appointment(desc, year, month, day, time)
{

}

bool Weekly::occurs_on(int year, int month, int day)
{
	date aDate(Appointment::get_day(), Appointment::get_month(), Appointment::get_year());
	date inDate(day, month, year);

	if (aDate.day_of_week() == inDate.day_of_week())
	{
		return true;
	}
	else
	{
		return false;
	}
}