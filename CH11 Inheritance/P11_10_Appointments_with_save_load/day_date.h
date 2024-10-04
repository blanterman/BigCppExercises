/*	This class creates a date object given the passed date information. With 
the date information other information can be calculated (eg day of the week)

Bryson Lanterman 20190304
*/

#include "stdafx.h"

class date
{
public:
	/**
		Constructs a date with no day month or year
	*/
	date();
	/**
		Constructs a date with given day month and year
		@param d day number of the date
		@param m month number of the date
		@param y year number of the date
	*/
	date(int d, int m, int y);
	/**
		Gets the day number of the date object
	*/
	int get_day() const;
	/**
		Gets the month number of the date object
	*/
	int get_month() const;
	/**
		Gets the year number of the date object
	*/
	int get_year() const;
	/**
		Computes the day of the week of the date object
		@return an integer representing the day of the week of the date object
		0 = Saturday
		1 = Sunday
		2 = Monday
		3 = Tuesday
		4 = Wednesday
		5 = Thursday
		6 = Friday
	*/
	int day_of_week();
private:
	int day;
	int month;
	int year;
};