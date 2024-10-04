/*  Exercise P12.3. Letter Frequencies. If you encrypt a file using the cipher 
of the preceding exercise, it will have all of its letters jumbled up, and it 
doesn't look as if there was any hope of decrypting it without knowing the 
keyword. Guessing the keyword seems hopeless too. There are just too many 
possible keywords. However, someone who is trained in decryption will be able 
to break this cipher in no time at all. The average letter frequencies of 
English letters are well known. The most common letter is E, which occurs about
13 percent of the time. Here are the average frequencies of the letters:

A  8%   H  4%   O  7%   U  3%
B <1%   I  7%   P  3%   V <1%
C  3%   J <1%   Q <1%   W  2%
D  4%   K <1%   R  8%   X <1%
E 13%   L  4%   S  6%   Y  2%
F  3%   M  3%   T  9%   Z <1%
G  2%   N  8%

Write a program that reads an input file and displays the letter frequencies in
that file. Such a tool will help a code breaker.If the most frequent letters 
in an encrypted file are H and K, then there is an excellent chance that they 
are the encryptions of E and T.

Bryson Lanterman 20191011
*/

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

/**
	Outputs the usage information for the program
	@param program_name the name of this program
*/
void usage(std::string program_name)
{
	std::cout << "Usage: " << program_name << " infile\n";
	exit(1);
}

/**
	Outputs the file information when there is an error opening the file
	@param file_name the name of the file that is attempting to be opened
*/
void file_error(std::string file_name)
{
	std::cout << "Error opening file: " << file_name << "\n";
	exit(1);
}

/**
	Counts the quantity of each character (not case sensitive) in the given file
	@param infile referenced file stream
	@param alphabet array for the count of each number 0 - 25 is a - z
	@param totalChars referenced total number of characters processed
*/
void count_chars(std::ifstream& infile, int alphabet[], long& totalChars)
{
	char ch;
	int relativePositionUC = 0;
	int relativePositionLC = 0;
	while (infile.get(ch))
	{
		relativePositionUC = ch - 'A';
		relativePositionLC = ch - 'a';
		if ((0 <= relativePositionUC && relativePositionUC <= 25 ) || (0 <= relativePositionLC && relativePositionLC <= 25))
		{
			if (islower(ch))
			{
				ch = toupper(ch);
				relativePositionUC = ch - 'A';
			}
			alphabet[relativePositionUC]++;
			totalChars++;
		}
	}
}

/**
	Outputs the percent of each entry to the given total
	@param alphabet integer array of the count of items
	@param size size of the alphabet array
	@param total the total count (should equal sum of all array items)
*/
void output_freqs(int alphabet[], int size, int total)
{
	double freq = 0;
	char ch;
	for (int i = 0; i < size; i++)
	{
		ch = char(i);
		freq = (static_cast<double>(alphabet[i]) / static_cast<double>(total)) * 100.0;
		std::cout << char(ch + 'A') << ": " << freq << "%\n";
	}
}

int main(int argc, char* argv[])
{
	const int ALPHABET_SIZE = 26;
	if (argc != 2)
	{
		usage(std::string(argv[0]));
	}

	int alphabet[ALPHABET_SIZE];

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		alphabet[i] = 0;
	}

	long totalChars = 0;

	std::ifstream infile;
	infile.open(argv[1]);

	if (infile.fail())
	{
		file_error(std::string(argv[1]));
	}

	count_chars(infile, alphabet, totalChars);
	output_freqs(alphabet, ALPHABET_SIZE, totalChars);

	infile.close();

	return 0;
}