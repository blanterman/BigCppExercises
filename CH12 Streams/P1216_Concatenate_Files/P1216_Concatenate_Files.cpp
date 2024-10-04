/*	Exercise P12.16. Write a program that concatenates the contents of several 
files into one file. For example,

catfiles chapter1.txt chapter2.txt chapter3.txt book.txt

makes a long file book.txt that contains the contents of the files chapter1.txt, 
chapter2.txt, and chapter3.txt. The target file is always the last file 
specified on the command line.

Bryson Lanterman 20200624
*/
#include <iostream>
#include <fstream>
#include <string>

/**
	Prints the Usage Instructions
	@param program_name the name of this program
*/
void usage(std::string program_name)
{
	std::cout << "Usage: " << program_name
		<< "file1 file2 ... filen concatenatedfile\n";
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
	if (argc < 3)
	{
		usage(std::string(argv[0]));
	}

	// Use the last file listed as the file to write to
	std::ofstream outputFile;
	outputFile.open(std::string(argv[argc - 1]));

	std::ifstream inputFile;
	char ch;

	// Go through all of the files given but the last one
	for (int i = 1; i < argc - 1; i++)
	{
		// Try to open curren file, exit program if can't open
		inputFile.open(std::string(argv[i]));
		if (inputFile.fail())
		{
			open_file_error(std::string(argv[i]));
		}

		// Write the contents of the current input file to the output file
		// character by character
		while(inputFile.get(ch))
		{
			outputFile.put(ch);
		}

		// Clean up current input file to get ready for next
		inputFile.close();
	}

	// clean up
	outputFile.close();

	return 0;
}
