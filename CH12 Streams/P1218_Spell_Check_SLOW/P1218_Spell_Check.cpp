/*	Exercise P12.18. Write a program that checks the spelling of all words in a
file. It should read each word of a file and check whether it is contained in a
word list. A word list is available on most UNIX systems in the file
/usr/dict/words. (If you don'thave access to a UNIX system, your instructor
should be able to get you a copy." The program should print out all words that
it cannot find in the word list.

I am using a dictionary file that I found on the web with almost half a million
entries. I am going to start by loading that file into a vector. Since it is
sorted, I will then use a binary search to find entries.

I might be able to use the file itself as the data structure. I would need to
do some preprocessing first. I would have to be able to control the line length
so that I could track where I am in the file, then I would be able to just use
the get and put methods of the file stream for finding words in a binary search
style. Maybe do that later or if above solution sucks.

Bryson Lanterman 20200707

Soooooooo slow
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

/**
	Displays that the text file could not be read
	@param fileName file name
*/
void file_load_error(std::string fileName)
{
	std::cout << fileName << " could not be opened.\n";
}

/**
	Loads a dictionary from a dictionary file to a vector to be
*/
void load_dictionary(std::vector<std::string>& dict, std::ifstream& dictionaryFile)
{
	std::string word;
	while (std::getline(dictionaryFile, word))
	{
		dict.push_back(word);
	}
	std::cout << "Dictionary Loaded with " << dict.size() << " words.";
}

bool search_dictionary(std::vector<std::string> dictionary, std::string word)
{
	long min = 0;
	long max = dictionary.size() - 1;
	long index;
	std::string dictWord;
	while (min <= max)
	{
		index = (max + min) / 2 ;
		dictWord = dictionary[index];
		if (dictWord == word)
		{
			return true;
		}
		if (dictWord > word)
		{
			max = index - 1;
		}
		if (dictWord < word)
		{
			min = index + 1;
		}
	}
	return false;
}

void spell_check(std::vector <std::string>& dictionary, std::ifstream& fileToCheck)
{
	std::string word;
	std::cout << "These words cannot be found in your dictionary:\n\n";
	while (fileToCheck >> word)
	{
		if (!search_dictionary(dictionary, word))
		{
			std::cout << word << "\n";
		}
	}
}

int main()
{
	std::ifstream dictFile;
	dictFile.open("wordlist.txt");
	if (dictFile.fail())
	{
		std::cout << "You did something with the dictionary\n";
		return -1;
	}
	std::vector<std::string> dictionary;
	load_dictionary(dictionary, dictFile);

	std::string fileName;
	std::ifstream fileToCheck;
	std::string response;
	while (true)
	{
		std::cout << "Please enter a file name with extension to spell check.\n"
			<<  "Make sure it is in the same directory as this program.\n\n";
		std::getline(std::cin, fileName);
		fileToCheck.open(fileName);
		if (fileToCheck.fail())
		{
			file_load_error(fileName);
		}
		else
		{
			spell_check(dictionary, fileToCheck);
		}
		std::cout << "Enter Y to check another file\n";
		std::getline(std::cin, response);
		if (response != "Y")
		{
			dictFile.close();
			fileToCheck.close();
			return -2;
		}
	}
	return 0;
}