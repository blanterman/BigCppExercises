/*	Exercise P12.1. Write a program that asks the user for a file name and 
displays the number of characters, words, and lines in that file. Then have 
the program ask for the name of the next file. When the user enters a file 
that doesn't exist (sucha as an empty string), the program should exit.

Bryson Lanterman 20190816

*/

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	// File Stream Variables
	std::string fileName;
	std::ifstream fileToCount;
	
	// Initialize counting variables
	long chars = 0;
	long words = 0;
	long lines = 0;
	
	// Initialize input variables for parsing the files
	char ch;
	std::string word;
	std::string line;
	
	// Welcome Message
	std::cout << "Welcome to the CharWordLine Counter Program!\n\n";
	
	// Main loop
	while (true)
	{
		// Reset variables for reruns
		fileName.clear();
		chars = 0;
		words = 0;
		lines = 0;

		// User prompt to input file name
		std::cout << "What file would you like me to analyze?\n"
			<< "filename: ";
		
		std::cin >> fileName;
		
		// Try to open the specified file
		fileToCount.open(fileName);

		if (fileToCount.fail()) // Specified file cannot be found -> close the program
		{
			std::cout << "Error opening " << fileName << "\n"
				<< "Closing Program\n";
			return 1;
		}
		
		//count characters
		while (fileToCount.get(ch))
		{
			if (ch != '\n') // Omit the newline characters in the count
			{
				chars++;
			}
		}

		// Reset (Close then open) so we can parse it again to count words
		fileToCount.close();
		fileToCount.open(fileName);

		//count words
		while (fileToCount >> word)
		{
			if (word.length() > 1) // Omit single characters
			{
				words++;
			}
		}

		// Reset (Close then open) so we can parse it again to count lines
		fileToCount.close();
		fileToCount.open(fileName);
		
		//count lines
		while (std::getline(fileToCount, line))
		{
			lines++;
		}
		
		// Close the file
		fileToCount.close();
		
		// Report
		std::cout << "Number of Characters (without Newline Characters): " << chars << "\n"
			<< "Number of Words: " << words << "\n"
			<< "Number of Lines: " << lines << "\n\n";
	}

	return 0;
}