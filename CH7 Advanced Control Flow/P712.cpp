/* The Game of Nim. This is a well-known game with a number of variants. The following variant 
has an interesting winning strategy. Two players alternately take parbels from a pile. In each 
move, a player chooses how many marbles to take. The player must take at least one but at most 
half of the marbles. Then the other player takes a turn. The player who takes the last marbel 
loses.

You will write a program in which the computer plays against a human opponent. Generate a random 
integer between 10 and 100 to denote the initial size of the pile. Generate a random integer 
between 0 and 1 to decide whether the computer or the human takes the first turn. Generate a 
random integer between 0 and 1 to decide whether the computer plays SMART or STUPID. In stupid 
mode the computer simply takes a random legal value (between 1 and n/2) from the pile whenever it 
has a turn. In smart mode the computer takes off enough marbles to make the size of a pile a 
power of 2 minus 1 - that is 3, 7, 15, 31 or 63. That is always a legal move, except if the size 
of the pile is currently one less than a power of two. In that case the computer makes a random 
legal move.

You will note that the computer cannot be beaten in smart mode when it has the first move, unless 
the pile size happens to be 15, 31, or 63. Of course, a human player who has the first turn and 
know the winning strategy can win against the computer.

	@file P712.cpp
	@author Bryson Lanterman
	@date 2018-02-22
	@version N/A
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MARB_MIN = 10;
const int MARB_MAX = 100;

/**
	Returns a psuedo-random intger between the input values
	@param low integer lower bound on random number
	@param high integer upper bound on random number
	@raturn randResult integer random int between low and high
*/
int pRand(int low, int high)
{
	int randResult = 0;
	randResult = (rand() % (high - low + 1)) + low;
	return randResult;
}

/**
	Asks the player to remove a valid amount of marbles from the pile.
	@param &marbCount integer of the current count of marbles
*/
void playerTurn(int& marbCount)
{
	int maxRemove = marbCount / 2;
	int remAmount = 0;
	bool validAmount = false;
	while (!validAmount)
	{
		cout << "Enter number to remove between 1 and " << maxRemove << "\n";
		cin >> remAmount;
		if (remAmount >= 1 && remAmount <= maxRemove)
		{
			validAmount = true;
			marbCount -= remAmount;
		}
		else
		{
			cout << "Amount Input was invalid. \n";
		}
	}
}

/**
	Performs a valid move by the computer.
	@param &marbCount integer of the current count of marbles
	@param state integer indicating the state of the computer: 0 - dumb, 1 - smart.
*/
void computerTurn(int& marbCount, int state)
{
	int maxRemove = marbCount / 2;
	int minRemove = 1;
	int posMin = marbCount - maxRemove;
	int posMax = marbCount - minRemove;
	if (state == 0)
	{
		int remAmount = pRand(minRemove, maxRemove);
		marbCount -= remAmount;
	}
	else if (state == 1)
	{
		if (posMin <= 63 && posMax >= 63)
		{
			marbCount = 63;
		}
		else if (posMin <= 31 && posMax >= 31)
		{
			marbCount = 31;
		}
		else if (posMin <= 15 && posMax >= 15)
		{
			marbCount = 15;
		}
		else if (posMin <= 7 && posMax >= 7)
		{
			marbCount = 7;
		}
		else if (posMin <= 3 && posMax >= 3)
		{
			marbCount = 3;
		}
		else
		{
			int remAmount = pRand(minRemove, maxRemove);
			marbCount -= remAmount;
		}
	}
	
}

int main()
{
	bool contPlay = true;

	while (contPlay)
	{
		//Seed the random function with current time
		srand(time(NULL));
		//Initialize game settings
		int marbleCount = pRand(MARB_MIN, MARB_MAX);
		int currPlay = pRand(0, 1);
		int compState = pRand(0, 1);

		while (marbleCount > 1)
		{
			cout << "Pile contains " << marbleCount << " marbles. \n";
			if (currPlay == 0)
			{
				playerTurn(marbleCount);
			}
			else 
			{
				computerTurn(marbleCount, compState);
			}
			if (marbleCount == 1)
			{
				cout << "Pile contains " << marbleCount << " marble. \n";
				if (currPlay == 1)
				{
					cout << "You Lose! \n";
				}
				else
				{
					cout << "You Win! \n";
				}
				contPlay = false;
			}
			if (currPlay == 0)
			{
				currPlay = 1;
			}
			else if (currPlay == 1)
			{
				currPlay = 0;
			}
		}
	}
	
	return 0;
}
