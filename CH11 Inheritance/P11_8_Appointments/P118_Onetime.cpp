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

Onetime::Onetime()
	:Appointment()
{

}

Onetime::Onetime(string desc, int year, int month, int day, int time)
	:Appointment(desc, year, month, day, time)
{

}

bool Onetime::occurs_on(int year, int month, int day)
{
	if (year == Appointment::get_year() && month == Appointment::get_month() && day == Appointment::get_day())
	{
		return true;
	}
	else
	{
		return false;
	}
}