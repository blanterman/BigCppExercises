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
#include "P1110_Weekly.h"
#include "day_date.h"

Weekly::Weekly()
	:Appointment()
{

}

Weekly::Weekly(std::string desc, int year, int month, int day, int time)
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

void Weekly::save(std::ostream& out)
{
	out << "Weekly\n"
		<< Appointment::get_description() << "\n"
		<< Appointment::get_year() << "\n"
		<< Appointment::get_month() << "\n"
		<< Appointment::get_day() << "\n"
		<< Appointment::get_time() << "\n"
		<< "\n";
}

void Weekly::load(std::istream& in)
{
	std::string desc;
	std::string remainder;
	int year = 0;
	int month = 0;
	int day = 0;
	int time = 0;
	std::getline(in, desc);
	in >> year >> month >> day >> time;
	*this = Weekly(desc, year, month, day, time);
	std::getline(in, remainder);
}