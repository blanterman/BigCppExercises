/*  Exercise P12.4. Vigenere cipher. The trouble with a monoalphabetic cipher 
is that it can be easily broken by frequency analysis. The so-called Vigenere 
cipher overcomes this problem by encoding a letter into one of several cipher 
letters, depending on its position in the input document. Choose a keyword, 
for example TIGER. Then encode the first letter of the input text like this:

ABCDEFGHIJKLMNOPQRSTUVWXYZ
||||||||||||||||||||||||||
TUVWXYZABCDEFGHIJKLMNOPQRS

The encoded alphabet is just the regular alphabet shifted to start at T, the 
first letter of the keyword TIGER. The second letter is encrypted according to 
the following map:

ABCDEFGHIJKLMNOPQRSTUVWXYZ
||||||||||||||||||||||||||
IJKLMNOPQRSTUVWXYZABCDEFGH

The third, fourth, and fifth letters in the input text are encrypted using the 
alphabet sequences beginning with the characters G, E, and R, and so on. 
Because the key is only five letters long, the sixth letter of the input text 
is encrypted in the same way as the first.

Write a program that encrypts or decrypts an input text according to this 
cipher.

Bryson Lanterman 20191015
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
	Creates the mapping tables for encryption/decryption
	@param upperAlph pointer to array of uppercase alphabet in ascending order
	@param upperVals pointer to vector of uppercase encryption values
	@param lowerAlph pointer to array of lowercase alphabet in ascending order
	@param lowerVals pointer to vector of lowercase encryption values
	@param keyword the keyword to create the encryption values
	@param numVals integer representing the number of letters in the alpabet 
*/
void create_tables(std::vector<std::vector<char>>& upperVals, std::vector<std::vector<char>>& lowerVals, std::string keyword, int numVals)
{
	char ch;
	std::vector<char> vals;
	int relativePoss = 0;
	// Create vector of vectors of all encrypted capital letters using keyword
	for (int i = 0; i < keyword.size(); i++)
	{
		ch = keyword[i];
		vals.clear();
		
		if (islower(keyword[i]))
		{
			ch = toupper(ch);
		}
		
		relativePoss = ch - 'A';
		
		for (int j = 0; j < numVals; j++)
		{
			vals.push_back((relativePoss + j) % (numVals) + 'A');
		}

		upperVals.push_back(vals);

		vals.clear();

		ch = tolower(ch);

		relativePoss = ch - 'a';
		
		for (int j = 0; j < numVals; j++)
		{
			vals.push_back((relativePoss + j) % (numVals) + 'a');
		}

		lowerVals.push_back(vals);
	}


}

/**
	Encrypts a character using the Random Monoalphabet cipher
	@param ch the character to encrypt
	@param decrypt true if decryption is wanted
	@param keyword the keyword used for the cipher
	@return the encrypted character
*/
char encrypt(char ch, std::string keyword, bool decrypt, long count)
{
	const int ALPHABET_SIZE = 26;


	/* Get the relative value of the character. If the character is valid it 
	   will be between 0 and 25 */
	int chValUC = ch - 'A'; 
	int chValLC = ch - 'a';
	
	// Instantiate encryption tables
	std::vector<std::vector<char>> valsUC;
	std::vector<std::vector<char>> valsLC;
	
	// Populate encryption tables
	create_tables(valsUC, valsLC, keyword, ALPHABET_SIZE);

	if (decrypt) // look in the encrypted values to decrypt them
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (ch == valsUC[count % keyword.size()][i])
			{
				ch = 'A' + i;
				i = ALPHABET_SIZE - 1; // stop once the letter is found.
			}
			if (ch == valsLC[count % keyword.size()][i])
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
			ch = valsUC[count % keyword.size()][chValUC];
		}
		if (0 <= chValLC && chValLC <= 25)
		{
			ch = valsLC[count % keyword.size()][chValLC];
		}
	}
			
	return ch;
}

void encrypt_file(std::istream& in, std::ostream& out, std::string keyword, bool decrypt)
{	
	char ch;
	long count = 0;
	while(in.get(ch))
	{
		out.put(encrypt(ch, keyword, decrypt, count));
		count++;
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