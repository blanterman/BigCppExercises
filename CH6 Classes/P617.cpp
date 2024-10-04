#include "stdafx.h"
#include "Message.h" //"ccc_time" <iostream> <string>

int main()
{
	Message email("Bryson", "Shannon", "");
	email.append("Dearest Shannon, \n\nI just want to tell you ");
	email.append("that I love you very much. \n\n");
	email.append("Yours Truly,\n\n");
	email.append("Bryson");
	email.print();
	return 0;
}