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

	Exercise P11.10. Improve the appointment book program of the preceding 
exercises by letting the user save the appointment data to a file and reload 
the data from a file. The saving part is straightforward: Make a virtual 
function save. Save out the type, description, date and time. The loading part
is not so easy. You must first determine the type of the appointment to be 
loaded, create an object of that type with its default constructor, and then 
call a virtual load function to load the remainder.

Bryson Lanterman 20190311
*/
#include "stdafx.h"
#include "P1110_Appointment.h"

Appointment::Appointment()
{
	aYear = 0;
	aMonth = 0;
	aDay = 0;
	aTime = 0;
}

Appointment::Appointment(std::string desc, int appYear, int appMonth, int appDay, int appTime)
{
	description = desc;
	aYear = appYear;
	aMonth = appMonth;
	aDay = appDay;
	aTime = appTime;
}

bool Appointment::occurs_on(int year, int month, int day)
{
	if (year == aYear && month == aMonth && day == aDay)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Appointment::save(std::ostream& out)
{

}

void Appointment::load(std::istream& in)
{

}

std::string Appointment::get_description() const
{
	return description;
}

int Appointment::get_year() const
{
	return aYear;
}

int Appointment::get_month() const
{
	return aMonth;
}

int Appointment::get_day() const
{
	return aDay;
}

int Appointment::get_time() const
{
	return aTime;
}