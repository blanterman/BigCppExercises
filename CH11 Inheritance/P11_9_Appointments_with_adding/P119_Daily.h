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
#include "P119_Appointment.h"

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
	Daily(string desc, int year, int month, int day, int time);
	/**
		Returns true if the daily appointment occurs on the given date
		@return true if the daily appointment date matches the given date
	*/
	virtual bool occurs_on(int year, int month, int day);
};