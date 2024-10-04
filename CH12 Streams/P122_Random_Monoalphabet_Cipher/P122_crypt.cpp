/*	Exercise P12.2. Random monoalphabet cipher. The Caesar cipher, to shift all
letters by a fixed amount, is ridiculously easy to crack - just try out all 25
keys. Here is a better idea. As the key, don't use numbers but words. Suppose 
the keyword is FEATHER. Then you first remove duplicate letters, yielding 
FEATHR, and append the other letterss of the alphabet in reverse order:

FEATHRZYXWVUSQPONMLKJIGDCB

Now encrypt the letters as follows

ABCDEFGHIJKLMNOPQRSTUVWXYZ
||||||||||||||||||||||||||
FEATHRZYXWVUSQPONMLKJIGDCB

Write a program that encrypts or decrypts a file using this cipher. For 
example,

crypt -d -kFEATHER encrypt.txt output.txt

decrypts a file using the keyword FEATHER. It is an error not to supply a 
keyword.


Bryson Lanterman 20191007
*/

#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <ctype.h>

/**
	Prints out the usage instructions
	@param program_name the name of this program
*/
void usage(std::string program_name)
{
	std::cout << "Usage: " << program_name
		<< " [-d] [-kkeyword] infile outfile\n";
	exit(1);
}

/**
	Prints file opening error message
	@param filename the name of the file that could not be opened
*/
void open_file_error(std::string filename)
{
	std::cout << "Error opening file " << filename << "\n";
	exit(1);
}

/**
	removes duplicate entries from a vector using the following method:
	
	Starts at the second element ends at the last element.
	
	Looks at the previous elements for a match.
	
	If a match is found, the current element is deleted and all following 
	elements shift to the left.
	
	When an element is deleted and a shift occurs, the same index is used for 
	the next element to be checked.

	@param v vector with potential duplicates
*/
void remove_duplicates(std::vector<char>& v)
{
	for (int i = 1; i < v.size(); i++)	// Start at first element end at last
	{
		for (int j = 0; j < i; j++)		// Search all previous elements
		{
			if (v[j] == v[i])			// Match found condition
			{
				v.erase(v.begin() + i); // Remove ith element and shift to left
				i--;					// Adjust index for the shift.
			}
		}
	}
}

/**
	Creates the mapping tables for encryption/decryption
	@param upperAlph pointer to array of uppercase alphabet in ascending order
	@param upperVals pointer to vector of uppercase encryption values
	@param lowerAlph pointer to array of lowercase alphabet in ascending order
	@param lowerVals pointer to vector of lowercase encryption values
	@param keyword the keyword to create the encryption values
	@param numVals integer representing the number of letters in the alpabet 
*/
void create_tables(std::vector<char>& upperVals, std::vector<char>& lowerVals, std::string keyword, int numVals)
{
	// Create vector of all encrypted capital letters using keyword
	for (int i = 0; i < keyword.length(); i++)
	{
		if (islower(keyword[i]))
		{
			upperVals.push_back(toupper(keyword[i]));
		}
		else
		{
		upperVals.push_back(keyword[i]);
		}
	}
	for (int i = numVals - 1; i >=0 ; i--)
	{
		upperVals.push_back('A' + i);
	}
	remove_duplicates(upperVals);

	// Create vector of all encrypted lower case letter using keyword
	for (int i = 0; i < keyword.length(); i++)
	{
		if (isupper(keyword[i]))
		{
			lowerVals.push_back(tolower(keyword[i]));
		}
		else
		{
		lowerVals.push_back(keyword[i]);
		}
	}
	for (int i = numVals - 1; i >=0 ; i--)
	{
		lowerVals.push_back('a' + i);
	} 
	remove_duplicates(lowerVals);
}

/**
	Encrypts a character using the Random Monoalphabet cipher
	@param ch the character to encrypt
	@param decrypt true if decryption is wanted
	@param keyword the keyword used for the cipher
	@return the encrypted character
*/
char encrypt(char ch, std::string keyword, bool decrypt)
{
	const int ALPHABET_SIZE = 26;

	/* Get the relative value of the character. If the character is valid it 
	   will be between 0 and 25 */
	int chValUC = ch - 'A'; 
	int chValLC = ch - 'a';
	
	// Instantiate encryption tables
	std::vector<char> valsUC;
	std::vector<char> valsLC;
	
	// Populate encryption tables
	create_tables(valsUC, valsLC, keyword, ALPHABET_SIZE);

	if (decrypt) // look in the encrypted values to decrypt them
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (ch == valsUC[i])
			{
				ch = 'A' + i;
				i = ALPHABET_SIZE - 1; // stop once the letter is found.
			}
			if (ch == valsLC[i])
			{
				ch = 'a' + i;
				i = ALPHABET_SIZE - 1; // stop once the letter is found.
			}
		}
	}
	else // use the relative value of the char as index to encrypt
	{
		if (0 <= chValUC && chValUC <= 25)
		{
			ch = valsUC[chValUC];
		}
		if (0 <= chValLC && chValLC <= 25)
		{
			ch = valsLC[chValLC];
		}
	}
			
	return ch;
}

void encrypt_file(std::istream& in, std::ostream& out, std::string keyword, bool decrypt)
{	
	char ch;
	while(in.get(ch))
	{
		out.put(encrypt(ch, keyword, decrypt));
	}
	
}


int main(int argc, char* argv[])
{
	bool decrypt = false;
	std::string keyword;
	int nfile = 0;

	std::ifstream infile;
	std::ofstream outfile;

	if (argc < 3 || argc > 5)
	{
		usage(std::string(argv[0]));
	}

	int i;
	for (i = 1; i < argc; i++)
	{
		std::string arg = std::string(argv[i]);
		if (arg.length() >= 2 && arg[0] == '-')
		// its a command argument
		{
			char option = arg[1];
			if (option == 'd')
			{
				decrypt = true;
			}
			else if (option == 'k')
			{
				keyword = arg.substr(2, arg.length() - 2);
				if (keyword.length() == 0)
				{
					usage(std::string(argv[0]));
				}
			}
		}
		else
		{
			nfile++;
			if (nfile == 1)
			{
				infile.open(arg.c_str());
				if (infile.fail()) 
				{
					open_file_error(arg);
				}

			}
			else if (nfile == 2)
			{
				outfile.open(arg.c_str());
				if (infile.fail())
				{
					open_file_error(arg);
				}
			}
		}
	}
	if (nfile != 2)
	{
		usage(std::string(argv[0]));
	}

	encrypt_file(infile, outfile, keyword, decrypt);
	infile.close();
	outfile.close();

	return 0;
}