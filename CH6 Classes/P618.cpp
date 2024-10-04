#include "stdafx.h"
#include "Mailbox.h"

int main()
{
	Mailbox mb1;
	mb1.add_message(Message("Bryson", "Shannon", "I love you"));
	mb1.add_message(Message("Shannon", "Bryson", "I love you too"));
	mb1.add_message(Message("Matthew", "Mom And Dad", "I love you GAGA!"));
	mb1.print_mail();
	Message m1 = mb1.get_message(2);
	m1.print();
	mb1.remove_message(3);
	mb1.print_mail();
	mb1.remove_message(2);
	mb1.print_mail();
	mb1.remove_message(1);
	mb1.print_mail();
	return 0;
}