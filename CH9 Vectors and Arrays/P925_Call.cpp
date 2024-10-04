#include "stdafx.h"
#include "P925_Call.h"
#include <regex>

/*
Default Constructor.
*/
P925_Call::P925_Call()
{

}

/*
Constructor
*/
P925_Call::P925_Call(string destIn, string startTime, int length, string day)
{
	destination = destIn;
	startingTime = time_to_dec(startTime);
	callLength = static_cast<double>(length) / 60.0;
	weekday = day;
}

/*
returns the destination
@return destination
*/
string P925_Call::get_destination() const
{
	return destination;
}

/*
returns the start time in decimal form
@return startingTime
*/
double P925_Call::get_startTime() const
{
	return startingTime;
}

/*
returns call length decimal representation of hours
@return callLength
*/
double P925_Call::get_length() const
{
	return callLength;
}

/*
returns weekday of call
@return weekday
*/
string P925_Call::get_day() const
{
	return weekday;
}

/*
Helper function that converts the input time from a string to a decimal:
example: 10:30 PM = 22.5
*/
double P925_Call::time_to_dec(string stime)
{
	regex reg("\([0-9]{1,2}):([0-9]{2}) ?(AM|PM)");
	smatch matches;
	regex_search(stime, matches, reg);
	if (matches.empty())
	{
		return -1.0;
	}
	int hours = stoi(matches[1]);
	double minutes = stod(matches[2]);
	if (matches[3].str().empty())
	{
		return static_cast<double>(hours) + minutes / 60.0;
	}
	else
	{
		hours = hours % 12;
		if (matches[3] == "AM")
		{
			return static_cast<double>(hours) + minutes / 60.0;
		}
		if (matches[3] == "PM")
		{
			return static_cast<double>(hours + 12) + minutes / 60.0;
		}
		return -1.0;
	}
}
string destination;
double startingTime;
double callLength;
string weekday;
