#include "stdafx.h"
#include "Message.h" //#include <string> is here
#include "ccc_time.h"
#include <iostream>

Message::Message()
{
}

Message::Message(string s, string r, string m)
{
	sender = s;
	recipient = r;
	Time start();
	message = m;
}

void Message::append(string line)
{
	message = message + line;
}

string Message::to_string() const
{
	return "From: " + sender + "\nTo: " + recipient + "\n" + message + "\n";
}

void Message::print() const
{
	cout << to_string();
}

