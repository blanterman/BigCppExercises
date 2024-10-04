/*	Exercise 12.17. Write a program find that searches all files specified on the command line and prints out all lines containing a keyword. For example, if you call 

find Tim report.txt address.txt homework.cpp

then the program might print 

report.txt: discussed the results of my meeting with Tim T
address.txt: Torrey, Tim|11801 Trenton Court|Dallas|TX
address.txt: Walters, Minnie|59 Timothy Circle|Detroit|MI
homework.cpp: Time now;

The keyword is always the first command line argument

Bryson Lanterman 20200702

*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

/**
	Prints the usage instructions for the program
	@param program_name string name of the program
*/
void usage(std::string program_name)
{
	std::cout << "Usage: " << program_name
		<< "keyword file1 file2 file3 ... filen\n";
	exit(1);
}

/**
	Prints file opening error message
	@param fileName the name of the file that could not be opened
*/
void open_file_error(std::string fileName)
{
	std::cout << fileName << " failed to open\n";
	exit(1);
}

/**
	Searches a file line by line for the given word and prints out the line if found
	@param keyword word to lood for in the file
	@param inFile input file stream to look through
	@param fileName name of current input file
*/
void search_file(std::string keyword, std::ifstream& inFile, std::string fileName)
{
	std::string line;
	while (std::getline(inFile, line))
	{
		if (line.find(keyword) != std::string::npos)
		{
			std::cout << fileName << ": " << line << "\n";
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		usage(std::string(argv[0]));
	}
	std::string keyWord = std::string(argv[1]);
	std::ifstream inFile;
	std::string fileName;
	for (int i = 2; i < argc; i++)
	{
		fileName = std::string(argv[i]);
		inFile.open(fileName);
		if (inFile.fail())
		{
			open_file_error(fileName);
		}
		search_file(keyWord, inFile, fileName);
		inFile.close();
	}
	return 0;
}