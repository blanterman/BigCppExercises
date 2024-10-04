#include "stdafx.h"
#include "Message.h" //#include <string>, "ccc_time", namespace std.

class Mailbox
{
public:
	/**
		Constructor
	*/
	Mailbox();

	/**
		Adds a message to the mailbox by adding the to_string
		version of the message to the mail string.
		@param m Message to add to the 
	*/
	void add_message(Message m);

	/**
		reCreates and returns a message based on the order in which
		it was received
		@param i integer representing the message number
		@return message_obj Message object of the desired message.
	*/
	Message get_message(int i) const;

	/**
		removes a message based on the order in which it was received
		@param i integer representing the message number
	*/
	void remove_message(int i);

	/**
		used for testing only
	*/
	void print_mail() const;

private:
	string mail;
};