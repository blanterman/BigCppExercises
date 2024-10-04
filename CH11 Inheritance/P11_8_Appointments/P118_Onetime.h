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

class Onetime : public Appointment
{
public:
	/**
		Constructs a one time appointment with no description date or time
	*/
	Onetime();
	/**
		Constructs a one time appointment with given description date and time
		@param desc description of the one time appointment
		@param year year of the one time appointment
		@param month month of the one time appointment
		@param day day of the one time appointment
		@param time time of the one time appointment
	*/
	Onetime(string desc, int year, int month, int day, int time);
	/**
		Returns true if the one time appointment occurs on the given date
		@return true if the one time appointment date matches the given date
	*/
	virtual bool occurs_on(int year, int month, int day);
};