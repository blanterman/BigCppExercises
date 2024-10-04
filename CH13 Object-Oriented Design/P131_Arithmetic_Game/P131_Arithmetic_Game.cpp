/*	Exercise P13.1. Write a program that implements a different game, to teach
arithmetic to your baby brother. The progream tests addition and subtraction. In
level 1 it tests only addition of numbers less than 10 whose sum is less than 
10. In level 2 it tests addition of arbitrary one-digit numbers. In level 3 it 
tests subtraction of one-digit numbers with a nonnegative difference. Generate 
random problems and get the player input. The player gets up to two tries per 
problem. As in the clock game, advance from one level to the next when the 
player has achieved a score of five points.

Bryson Lanterman 20210503
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

/**
	Prompts the user for the desired level to start on
*/
int get_level()
{
	int level = 0;
	do
	{
		std::cout << "What level would you like to start on? (1-3) \n";
		std::cin >> level;
	} 
	while (1 > level || level > 3);
	return level;
}

/**
	Sets the seed of the random number generator
*/
void rand_seed()
{
	srand(time(NULL));
}

/**
	Returns a random integer in a range
	@param a the bottom of the range
	@param b the top of the range
	@return a random number x, a <= x <= b
*/
int rand_int(int a, int b)
{
	return a + rand() % (b - a + 1);
}

/**
	Generates a math problem and solution based on the level of play
	@param level level of play
	@param answer reference to the answer of the math problem
*/
std::string get_problem(int level, int& answer)
{
	int first = 0;
	int last = 0;
	// Level 1  tests only addition of number less than 10 whose sum is less than 10
	if (level == 1)
	{
		first = rand_int(0, 10);
		last = rand_int(0, 10 - first);
		answer = first + last;
		return std::to_string(static_cast<long long>(first)) + " + " + std::to_string(static_cast<long long>(last)) + " = ";
	}
	// Level 2 tests addition of arbitrary one-digit numbers
	if (level == 2)
	{
		first = rand_int(0, 9);
		last = rand_int(0, 9);
		answer = first + last;
		return std::to_string(static_cast<long long>(first)) + " + " + std::to_string(static_cast<long long>(last)) + " = ";
	}
	// Level 3 tests subtraction of one-digit numbers with a nonnegative difference
	if (level == 3)
	{
		first = rand_int(0, 10);
		last = rand_int(0, first);
		answer = first - last;
		return std::to_string(static_cast<long long>(first)) + " - " + std::to_string(static_cast<long long>(last)) + " = ";
	}
	return "Stupid Mistake, you have made";
}

/**
	Increases score and decides if the level needs to be increased
	@param level reference to current level
	@param score reference to current score
*/
void process_correct_answer(int& level, int& score)
{
	score++;
	if (score % 5 == 0 && level < 3)
	{
		level++;
	}
	std::cout << "You are correct.\n";
	
}

int main()
{
	// Seed random number generator
	rand_seed();

	// Set up game's variables
	int level = get_level();
	int score = 0;
	int answer = 0;
	bool cont = true;
	int guess;
	std::string response;

	// Main game loop
	do
	{
		std::string problem = get_problem(level, answer);  // Gets the math problem
		std::cout << problem;  // Poses the problem to the user
		std::cin >> guess;  // Gets the guess from the user

		// Allows for 2 tries for the user to get the answer correct
		if (guess != answer) // users answer was incorrect
		{
			std::cout << "Incorrect. Please try one more time.\n"; // informs user of incorrect answer
			std::cout << problem; // Re-poses the problem
			std::cin >> guess; // Gets the second guess from the user
			if (guess != answer) // user's second guess was incorrect
			{
				std::cout << "The correct answer was " << answer << ".\n"; // shows the correct answer
			}
			else // Second guess was correct
			{
				process_correct_answer(level, score); // increases score, may increase level
			}
		}
		else // first guess was correct
		{
			process_correct_answer(level, score); // increases score, may increase level
		}

		// Ask the user if they want to continue
		std::cout << "Would you like to continue? (y/n)";
		std::cin >> response;
		if (response != "y")
		{
			cont = false;
		}
	} 
	while (cont);

	return 0;
}