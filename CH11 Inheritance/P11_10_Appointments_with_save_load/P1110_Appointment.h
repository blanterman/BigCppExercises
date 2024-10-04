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

#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>

class Appointment
{
public:
	/**
		Constructs an appointment with no description date or time
	*/
	Appointment();
	/**
		Constructs an appointment with the given description date and time
		@param desc string description of appointment
		@param appYear year of appointment
		@param appMonth month of appointment
		@param appDay day of appointment
		@param appTime integer appointment time in the form hhmm military time
	*/
	Appointment(std::string desc, int appYear, int appMonth, int appDay, int appTime);
	/**
		Returns true if the appointment is on the given day
		@return true if the appointment date matches the given day
	*/
	virtual bool occurs_on(int year, int month, int day);
	/**
		Outputs the appointment information to a file
		@param out dereferenced output stream to write to
	*/
	virtual void save(std::ostream& out);
	/**
		Gets appointment information from a file
		@param in dereferenced input stream to write to
	*/
	virtual void load(std::istream& in);
	/**
		Gets the appointment description
		@return description of appointment
	*/
	std::string get_description() const;
	/**
		Gets the year of the appointment
		@return year of the appointment
	*/
	int get_year() const;
	/**
		Gets the year of the appointment
		@return month of the appointment
	*/
	int get_month() const;
	/**
		Gets the day of the appointment
		@return day of the appointment
	*/
	int get_day() const;
	/**
		Gets the time of the appointment
		@return time of the appointment
	*/
	int get_time() const;
private:
	std::string description;
	int aYear;
	int aMonth;
	int aDay;
	int aTime;
};