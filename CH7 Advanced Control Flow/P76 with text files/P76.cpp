/*
	This program computes the Flesch Readability Index of a document. 
	I made a document the input stream and the program parses it one word at a time.
	The resulting Index is broken down like this:
	91 - 100		5th grader
	81 - 90			6th grader
	71 - 80			7th grader
	66 - 70			8th grader
	61 - 65			9th grader
	51 - 60			High school student
	31 - 50			College student
	0 - 30			College Graduate
	Less than 0		Law school graduate
*/


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	double num_words = 0;
	double syllables = 0;
	double sentences = 0;
	double index = 0.0;
	
	while(cin >> word)
	{
		num_words++;

		int word_length = word.length();
		
		// word length is corrected if there is a period
		if(word[word_length - 1] == '.')
		{
			sentences++;
			word_length--;
		}
		
		double word_sylls = 0;

		for(int i = 0; i < word_length; i++)
		{
			char curr = word[i];
			char next;
			// Look for a vowel to find a syllable
			if(curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u' || curr == 'y')
			{
				// e at the end of a word doesn't count as a syllable
				if(curr == 'e' && i == word_length - 1)
				{
				}
				// increase the vowel count and skip over double vowel
				else if(i != word_length - 1)
				{
					word_sylls++;
					next = word[i + 1];
					if(next == 'a' || next == 'e' || next == 'i' || next == 'o' || next == 'u' || next == 'y')
					{
						i++;
					}
				}
				// This executes if the word ends in something other than an e.
				else
				{
					word_sylls++;
				}
			}
		}

		// Every word contributes at least one syllable
		if(word_sylls == 0)
		{
			syllables++;
		}
		else
		{
			syllables += word_sylls;
		}
	}

	index = 206.835 - 84.6 * (syllables / num_words) - 1.015 * (num_words / sentences); // This eqation is in Big C++ first edition pp. 293
	cout << sentences << "\n" << num_words << "\n" << syllables << "\n" << index << "\n";
	return 0;
}