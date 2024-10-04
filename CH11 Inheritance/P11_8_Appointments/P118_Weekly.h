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
#include "P118_Appointment.h"

class Weekly : public Appointment
{
public:
	/**
		Constructs a weekly appointment with no description date or time
	*/
	Weekly();
	/**
		Constructs a weekly appointment with given description date and time
		@param desc description of the weekly appointment
		@param year year of the weekly appointment
		@param month month of the weekly appointment
		@param day day of the weekly appointment
		@param time time of the weekly appointment
	*/
	Weekly(string desc, int year, int month, int day, int time);
	/**
		Returns true if the weekly appointment occurs on the given date
		@return true if the weekly appointment date matches the given date
	*/
	virtual bool occurs_on(int year, int month, int day);
};