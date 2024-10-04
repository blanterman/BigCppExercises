/*	Exercise P12.15. Write a program copyfile that copies one file to another. 
The file names are specified on the command line. For example,

copyfile report.txt report.sav

Bryson Lanterman 20200624
*/
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

/**
	Prints usage instructions.
	@param program_name the name of this program
*/
void usage(std::string program_name)
{
	std::cout << "Usage: " << program_name
		<< "sourcefile destinationfile\n";
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

int main(int argc, char* argv[])
{	
	// Check that the user input the proper number of arguments
	if (5 < argc || argc < 3)
	{
		usage(std::string(argv[0]));
	}

	// Instantiate file streams
	std::ifstream sourceFile;
	std::ofstream destinationFile;

	// Open the source file and check to make sure it opened
	sourceFile.open(std::string(argv[1]));
	if (sourceFile.fail())
	{
		open_file_error(std::string(argv[1]));
	}
	
	// Open/create the destination file
	destinationFile.open(std::string(argv[2]));
	
	// Copy the file over a character at a time
	char ch;
	while(sourceFile.get(ch))
	{
		destinationFile.put(ch);
	}

	// Cleanup
	sourceFile.close();
	destinationFile.close();

	return 0;
}