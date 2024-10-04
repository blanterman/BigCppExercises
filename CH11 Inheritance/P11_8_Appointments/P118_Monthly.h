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

class Monthly : public Appointment
{
public:
	/**
		Constructs a monthly appointment with no description date or time
	*/
	Monthly();
	/**
		Constructs a monthly appointment with given description date and time
		@param desc description of the monthly appointment
		@param year year of the monthly appointment
		@param month month of the monthly appointment
		@param day day of the monthly appointment
		@param time time of the monthly appointment
	*/
	Monthly(string desc, int year, int month, int day, int time);
	/**
		Returns true if the monthly appointment occurs on the given date
		@return true if the monthly appointment date matches the given date
	*/
	virtual bool occurs_on(int year, int month, int day);
};