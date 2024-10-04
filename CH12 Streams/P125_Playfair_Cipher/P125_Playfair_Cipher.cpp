/*  Exercise P12.5. Playfair cipher. Another way of thwarting a simple letter 
frequency analysis of an encrypted text is to encrypt pairs of letters 
together. A simple scheme to do this is the Playfair cipher. You pick a 
keyword and remove duplicate letters from it. then you fill the keyword, and 
the remaining letters of the alphabet, into a 5x5 square. (Since there are only 
25 squares, I and J are considered the same letter.)

Here is such an arrangement with the keyword PLAYFAIR.

P L A Y F
I R C D E
G H K M N
O Q R S T
U V W X Z

To encrypt a letter pair, say AM, look at the rectangel with corners A and M:

P L a y F
I R c d E
G H k m N
O Q R S T
U V W X Z

the encoding of this pair is formed by looking at the other two corners of the 
rectangle, in this case, YK. If both letters happen to be in the same row or 
column, such as GO, simply swap the two letters. Decryption is done the same 
way.

Write a program that encrypts or decrypts an input text according to this 
cipher.

Bryson Lanterman 20191016
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
	@param upperVals pointer to vector of uppercase encryption values
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
	for (int i = 0; i < numVals; i++)
	{
		if (i != ('J' - 'A')) // Omit the letter J
		{
			upperVals.push_back('A' + i);
		}
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
	for (int i = 0; i < numVals; i++)
	{
		if (i != 'j' - 'a') // Omit the letter j
		{
			lowerVals.push_back('a' + i);
		}
	} 
	remove_duplicates(lowerVals);
}

/**
	Sets a pair of characters to their encrypted values according to the playfair cipher
	@param ch1 referenced first character to be encrypted
	@param ch2 referenced second character to be encrypted
	@param vals vector of characters arranged  for playfair cypher encryption with keyword
	@param alphabetSize size of alphabet used
	@param decrypt true if decrypt was selected
	@param adj integer value set to 1 if an adjustment is needed based on character situations
	@param int tableWidth integer width of the encryption table of characters
*/
void make_swaps(char& ch1, char& ch2, const std::vector<char>& vals, int alphabetSize, bool decrypt, int adj, int tableWidth)
{
	// encrypted table look up variables
	// Possition (index) in a vector translates to an (m, n) position in a 2d table by the equations:
	// m = index / height of table
	// n = index % width of table
	int pos1 = 0;
	int pos2 = 0;
	int m1 = 0;
	int m2 = 0;
	int n1 = 0;
	int n2 = 0;

	// Swapping buffer var
	int temp = 0;

	// Look through the key vector to get the first character's position
	for (int i = 0; i < alphabetSize - 1; i++)
	{
		if (ch1 == vals[i])
		{
			pos1 = i;
			i = alphabetSize - 1;
		}
	}

	// Look through the key vector to get the second character's position
	for (int i = 0; i < alphabetSize - 1; i++)
	{
		if (ch2 == vals[i])
		{
			pos2 = i;
			i = alphabetSize - 1;
		}
	}

	// Decrypt the characters based on their position
	if (decrypt)
	{
		// Convert position of first char to row number
		m1 = (pos1 / tableWidth - adj) % tableWidth;
		// take care of wrapping if adjustment caused wrapping case
		if (m1 == -1)
		{
			m1 += tableWidth;
		}
		// Convert position of first char to column number
		n1 = (pos1 % tableWidth - adj) % tableWidth;
		// take care of wrapping if adjustment caused wrapping case
		if (n1 == -1)
		{
			n1 += tableWidth;
		}
		// Convert position of second char to row number
		m2 = (pos2 / tableWidth - adj) % tableWidth;
		// take care of wrapping if adjustment caused wrapping case
		if (m2 == -1)
		{
			m2 += tableWidth;
		}
		// Convert position of second char to column number
		n2 = (pos2 % tableWidth - adj) % tableWidth;
		// take care of wrapping if adjustment caused wrapping case
		if (n2 == -1)
		{
			n2 += tableWidth;
		}
	}
	// If decryption isn't set, then encrypt the characters instead
	// wrapping in this case is taken care of by the modulus
	else
	{
		// Convert position of first char to row number
		m1 = (pos1 / tableWidth + adj) % tableWidth;
		// Convert position of first char to column number
		n1 = (pos1 % tableWidth + adj) % tableWidth;
		// Convert position of second char to row number
		m2 = (pos2 / tableWidth + adj) % tableWidth;
		// Convert position of second char to column number
		n2 = (pos2 % tableWidth + adj) % tableWidth;
	}

	// the two characters make a rectangle in the key table, to encrypt we swap the corners (swap the column number)
	// This also takes care of the case when the chars have the same row number. The chars are just swapped.
	temp = n2;
	n2 = n1;
	n1 = temp;

	// if the chars are in the same column, just swap the characters by swapping row numbers
	if (n1 == n2)
	{
		temp = m2;
		m2 = m1;
		m1 = temp;
	}

	// with the new coordinates we calculate the position (index)
	pos1 = m1 * tableWidth + n1;
	pos2 = m2 * tableWidth + n2;

	// use the index to set the encrypted values
	ch1 = vals[pos1];
	ch2 = vals[pos2];
}

/**
	Encrypts a pair of characters using the Playfair cipher
	@param ch1 reference to the first character to encrypt
	@param ch2 reference to the second character to encrypt
	@param decrypt true if decryption is wanted
	@param keyword the keyword used for the cipher
*/
void encrypt_pair(char& ch1, char& ch2, std::string keyword, bool decrypt)
{
	const int ALPHABET_SIZE = 26;
	const int TABLE_WIDTH = 5;
	bool UpLow = false;
	bool LowUp = false;
	bool UpUp = false;
	bool LowLow = false;

	// If the characters are J or j then turn them into I or i respectively
	if (ch1 == 'J' || ch1 == 'j')
	{
		ch1--;
	}

	if (ch2 == 'J' || ch2 == 'j')
	{
		ch2--;
	}

	// booleans for handling upper and lower case combinations
	UpLow = isupper(ch1) && islower(ch2);
	LowUp = islower(ch1) && isupper(ch2);
	UpUp = isupper(ch1) && isupper(ch2);
	LowLow = islower(ch1) && islower(ch2);
	
	// Instantiate encryption tables
	std::vector<char> valsUC;
	std::vector<char> valsLC;
	
	// Populate encryption tables
	create_tables(valsUC, valsLC, keyword, ALPHABET_SIZE);

	int adj = 0;

	if(UpLow)
	{
		ch1 = tolower(ch1);
		adj = ch1 == ch2 ? 1 : 0;
		make_swaps(ch1, ch2, valsLC, ALPHABET_SIZE, decrypt, adj, TABLE_WIDTH);
		ch1 = toupper(ch1);
	}

	if(LowUp)
	{
		ch2 = tolower(ch2);
		adj = ch1 == ch2 ? 1 : 0;
		make_swaps(ch1, ch2, valsLC, ALPHABET_SIZE, decrypt, adj, TABLE_WIDTH);
		ch2 = toupper(ch2);
	}

	if(UpUp)
	{
		adj = ch1 == ch2 ? 1 : 0;
		make_swaps(ch1, ch2, valsUC, ALPHABET_SIZE, decrypt, adj, TABLE_WIDTH);
	}

	if(LowLow)
	{
		adj = ch1 == ch2 ? 1 : 0;
		make_swaps(ch1, ch2, valsLC, ALPHABET_SIZE, decrypt, adj, TABLE_WIDTH);
	}
}

/**
	Sets the next two characters found in the stream and puts them in the buffer. 
	If there are non alphabetical characters at the beginning and/or in between the characters
	they are also put in the buffer. Order is preserved in the buffer.
	@param in input stream
	@param ch1 referenced first character
	@param ch2 referenced second character
	@param buffer referenced buffer vector for printing all information and preserving non alphabetic chars
	@return true if 1 or 2 characters were found
*/
bool get_next_2_chars(std::istream& in, char& ch1, char& ch2, std::vector<char>& buffer)
{
	char ch; // used to get one char at a time
	bool gotOne = false; // used to singify when we already have found one char

	while(in.get(ch)) // while there are still characters left to get
	{
		// checks if the character is alphabetic
		if ((0 <= ch - 'A' && ch - 'A' <= 25) || (0 <= ch - 'a' && ch - 'a' <= 25))
		{
			// If we have one already then set the second, push on to the buffer and return true
			if (gotOne)
			{
				ch2 = ch;
				buffer.push_back(ch2);
				return true;
			}
			// If one hasn't be found yet, populate the first one and push on to the buffer and signify that one has been found
			else
			{
				ch1 = ch;
				buffer.push_back(ch1);
				gotOne = true;
			}
		}
		else // even if we didn't find a character, we put what was found on to the buffer
		{
			buffer.push_back(ch);
		}
	}
	// If we went through the rest of the stream and ran out of chars but we found one character
	// we have an odd number of characters. In this case we set the second character to 'X' and push it on the buffer. 
	// then we return true
	if (gotOne)
	{
		ch2 = 'X'; 
		buffer.push_back(ch2);
		return true;
	}

	// if we didn't find any characters we return false, but there still might be data in the buffer
	return false;
}
/**
	Encrypts a text file two characters at a time using the playfair cipher
	and prints the encrypted characters to a new file
	@param in input stream file to be encrypted
	@param out output stream encrypted file
	@param keyword string used for encryption
	@param decrypt true if decryption is desired by user
*/
void encrypt_file(std::istream& in, std::ostream& out, std::string keyword, bool decrypt)
{	
	// character variables for input and encrypted values
	char ch1;
	char ch2;
	char ch1e;
	char ch2e;

	// buffer vector for parsing and printing non alphabetic input
	std::vector<char> buffer;

	// encrypt the file 2 characters at a time
	while(get_next_2_chars(in, ch1, ch2, buffer)) // get a buffer with all 2 chars and other chars too ie spaces, punctuation, etc
	{
		// Initialize encrypted characters as input chars
		ch1e = ch1;
		ch2e = ch2;
		
		// encrypt the characters
		encrypt_pair(ch1e, ch2e, keyword, decrypt);
		
		// Print out what is in the buffer, replacing the original characters with the encrypted ones
		for (int i = 0; i < buffer.size(); i++)
		{
			if(buffer[i] == ch1)
			{
				out.put(ch1e);
			}
			else if(buffer[i] == ch2)
			{
				out.put(ch2e);
			}
			else
			{
				out.put(buffer[i]);
			}
		}
		// clear the buffer before getting the next two character information
		buffer.clear();
	}

	// Print out all non alphabetic characters that are at the end of the file
	for (int i = 0; i < buffer.size(); i++)
	{
		out.put(buffer[i]);
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