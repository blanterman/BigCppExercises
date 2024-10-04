#include "stdafx.h"
#include <string>

using namespace std;

class Message
{
public:
	/**
		Default constructor
	*/
	Message();

	/**
		Constructor with the sender and recipient given. The
		sender and the recipient are set and a time stamp is
		set to the current time.
		@param s string sender of the message
		@param r string recipient of the message
		@param m string message
	*/
	Message(string s, string r, string m);

	/**
		appends a line of text to the message body
		@param line string to append to the message body
	*/
	void append(string line);

	/**
		makes the message into one long string
		@return str_msg string the entire message
	*/
	string to_string() const;

	/**
		prints the message text
	*/
	void print() const;

private:
	string recipient;
	string sender;
	string message;
};
