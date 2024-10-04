// P42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string card_in, card, suit;
	bool card_good = false, suit_good = false;


	cout << "Please provide the shorthand of the card and suit:";
	cin >> card_in;
	if (card_in.length() != 2)
	{
		cout << "invalid card\n";
		return 1;
	}
	card = card_in.substr(0,1);
	suit = card_in.substr(1,1);
	if (card == "A")
		card = "Ace";
	if (card == "2")
		card = "Two";
	if (card == "3")
		card = "Three";
	if (card == "4")
		card = "Four";
	if (card == "5")
		card = "Five";
	if (card == "6")
		card = "Six";
	if (card == "7")
		card = "Seven";
	if (card == "8")
		card = "Eight";
	if (card == "9")
		card = "Nine";
	if (card == "10")
		card = "Ten";
	if (card == "J")
		card = "Jack";
	if (card == "Q")
		card = "Queen";
	if (card == "K")
		card = "King";
	if (suit == "D")
		suit = "Diamonds";
	if (suit == "H")
		suit = "Hearts";
	if (suit == "S")
		suit = "Spades";
	if (suit == "C")
		suit = "Clubs";
	if (card.length() == 1 || suit.length() == 1)
	{
		cout << "improper input\n";
		return 1;
	}
	cout << card << " of " << suit << "\n";
	
}

