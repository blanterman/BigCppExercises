#include "stdafx.h"
#include "Mailbox.h"
#include <iostream>

/**
	Parses a string of messages and returns the ith one
	@param messages string of messages to be searched. It is 
	assumed that each message starts with a ">From:"
	@param i integer representing the message desired to be found
	@return message string of the ith message
*/
string find_message(string messages, int i)
{
	int count = 0, start_ind = 0, end_ind = 0;
	string current_string, message;

	string flag_word = ">From:";
	int flag_word_length = flag_word.length();

	for(int j = 0; j < messages.length() - flag_word_length - 1; j++)
	{
		current_string = messages.substr(j, flag_word_length);
		if(current_string == flag_word)
		{
			count++;
			if(count == i)
				start_ind = j;
			if(count == i + 1)
				end_ind = j - 1;
		}
		if(end_ind == 0 && j == messages.length() - flag_word_length - 2)
				end_ind = messages.length() - 1;
	}
	message = messages.substr(start_ind, end_ind - start_ind);
	return message;
}

/**
	Extracts the sender and the index of "To" from the 
	given message
	@param message string message with sender recipient and message
	@param i the index of the character before "To:"
	@return sender string of the senders name
*/

string find_sender(string message, int& i)
{
	string curr_chunk;
	int starting_index = 7;
	for(int j = starting_index; j < message.length() - 2; j++)
	{
		curr_chunk = message.substr(j, 3);
		if(curr_chunk == "To:")
			i = j - 1;
	}
	string sender = message.substr(starting_index, i - starting_index);
	return sender;
}


/**
	Extracts the recipient and the index of the beginning of the 
	message portion of the entire message
	@param message string message with sender recipient and message
	@param i the index of the character before "To:" to be updated
	to give the index of the beginning of the message.
	@return recipient string of the recipient's name
*/

string find_recipient(string message, int& i)
{
	string curr_chunk;
	int start = i + 5;
	for(int j = start; j < message.length(); j++)
	{
		curr_chunk = message.substr(j, 1);
		if(curr_chunk == "\n")
			i = j;
	}
	string recipient = message.substr(start, i - start);
	return recipient;
}

/**
	Parses a string of messages and locates the indeces of the ith one
	@param messages string of messages to be searched. It is 
	assumed that each message starts with a ">From:"
	@param i integer representing the message desired to be found
*/
void find_indeces(string messages, int i, int& beg, int& end)
{
	int count = 0;
	string current_string, message;

	string flag_word = ">From:";
	int flag_word_length = flag_word.length();

	for(int j = 0; j < messages.length() - flag_word_length - 1; j++)
	{
		current_string = messages.substr(j, flag_word_length);
		if(current_string == flag_word)
		{
			count++;
			if(count == i)
				beg = j;
			if(count == i + 1)
				end = j - 1;
		}
		if(end == 0 && j == messages.length() - flag_word_length - 2)
				end = messages.length() - 1;
	}
	
}

Mailbox::Mailbox()
{
}

void Mailbox::add_message(Message m)
{
	mail = mail + ">" + m.to_string();
}

Message Mailbox::get_message(int i) const
{
	string message_str;
	message_str = find_message(mail, i);

	string sender;
	int ind = 0;
	sender = find_sender(message_str, ind);

	string recipient;
	recipient = find_recipient(message_str, ind);

	string message_only;
	message_only = message_str.substr(ind + 1, message_str.length() - ind);
	
	Message message_obj(sender, recipient, message_only);

	return message_obj;
}

void Mailbox::remove_message(int i)
{
	int beg_ind = 0, end_ind = 0;
	find_indeces(mail, i, beg_ind, end_ind);
	mail = mail.substr(0, beg_ind) + mail.substr(end_ind + 1, mail.length() - end_ind - 1);
}

void Mailbox::print_mail() const
{
	cout << mail << "\n";
}