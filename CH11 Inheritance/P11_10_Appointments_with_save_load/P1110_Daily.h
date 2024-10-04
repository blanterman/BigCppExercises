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

class Daily : public Appointment
{
public:
	/**
		Constructs a daily appointment with no description date or time
	*/
	Daily();
	/**
		Constructs a daily appointment with given description date and time
		@param desc description of the daily appointment
		@param year year of the daily appointment
		@param month month of the daily appointment
		@param day day of the daily appointment
		@param time time of the daily appointment
	*/
	Daily(std::string desc, int year, int month, int day, int time);
	/**
		Returns true if the daily appointment occurs on the given date
		@return true if the daily appointment date matches the given date
	*/
	virtual bool occurs_on(int year, int month, int day);
	/**
		Outputs the daily appointment information to a file
		param out dereference output stream
	*/
	virtual void save(std::ostream& out);
	/**
		Creates a daily appointment using the information in the file
		param in dereferenced input stream 
	*/
	virtual void load(std::istream& in);
};