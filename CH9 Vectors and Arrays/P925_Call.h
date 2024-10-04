#include "stdafx.h"
#include <string>

using namespace std;

class P925_Call
{
public:
	/*	
		Default Constructor.
	*/
	P925_Call();

	/*
		Constructor
	*/
	P925_Call(string destIn, string startTime, int length, string day);

	/*
		returns the destination
		@return destination
	*/
	string get_destination() const;

	/*
		returns the start time in decimal form
		@return startingTime
	*/
	double get_startTime() const;

	/*
		returns call length in minutes
		@return callLength
	*/
	double get_length() const;

	/*
		returns weekday of call
		@return weekday
	*/
	string get_day() const;
	
private:
	/*
		Helper function that converts the input time from a string to a decimal: 
		example: 10:30 PM = 22.5
	*/
	double time_to_dec(string stime);
	string destination;
	double startingTime;
	double callLength;
	string weekday;
};
