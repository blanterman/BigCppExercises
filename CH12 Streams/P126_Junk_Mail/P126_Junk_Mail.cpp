/*	Exercise P12.6. Junk mail. Write a program that reads in two files: a 
template and a data-base. The template file contains text and tags. The tags 
have the form |1| |2| |3| ... and need to be replaced with the first, second,
third,... field in the current database record.

A typical database looks like this:

	Mr.|Harry|Hacker|1105 Torre Ave.|Cupertino|CA|95014
	Dr.|John|Lee|702 Ninth Street Apt. 4|San Jose|CA|95109
	Miss|Evelyn|Garcia|1101 S. University Place|Ann Arbor|MI|48105

And here is a typical form letter:

	To:
	|1| |2| |3|
	|4|
	|5|, |6| |7|

	Dear |1| |3|:

	You and the |3| family may be the lucky winners of $10,000,000 in the C++ 
	compiler clearinghouse sweepstakes!
	Just give us all your money and send us your children and that is that.

	Thanks,

	Your Mom

My implementation of this will create a unique file for each line in the 
data-base. In the case of this exercise there are three output files:

output0.txt
output1.txt
output2.txt

Bryson Lanterman 20191106
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/**
	Displays the usage information for the program
	@param programName the name of the program
*/
void usage(std::string programName)
{
	std::cout << programName << " DBFile TemplateFile OutputFile\n";
	exit(1);
}

/**
	Displays the file read error message
	@param DBFile string name of the database file
	@param tempFile string name of the template file
*/
void file_read_error(std::string DBFile)
{
	std::cout << DBFile << " can not be opened\n";
	exit(1);
}

/**
	Displays the file mismatch error message
	@param DBFile string name of the database file
	@param tempFile string name of the template file
*/
void file_match_error(std::string DBFile, std::string tempFile)
{
	std::cout << DBFile << " and " << tempFile << " do not coincide\n";
	exit(1);
}

/**
	Gets the next word in the database to be used as an entry
	@param instr reference to an input string stream to parse
	@param next string reference to be populated by the parser
	@return true if a word is found.
*/
bool get_next_entry(std::istringstream& instr, std::string& next)
{
	char ch;
	std::ostringstream outstr;
	bool foundOne = false;

	while(instr.get(ch))
	{
		if (ch != '|') // entries delimeted by a |
		{
			foundOne = true; // catch the last entry flag
			outstr.put(ch);
		}
		else // Once delimiter found populate the string and return true
		{
			next = outstr.str();
			return true;
		}
	}
	// this will be reached if the end of the string stream was reached
	if (foundOne) // if there was an entry found before the end of the file
	{
		next = outstr.str(); // populate the string and return true
		return true;
	}

	return false; // this will be reached if the string stream is empty
}

int get_index_and_leftovers(std::string word, std::string& leftovers)
{
	int index = 0;
	index = std::stoi(word.substr(1,word.size() - 2)) - 1;
	leftovers = word.substr(3,word.size() - 1);
	return index;
}

void replace_signifiers(std::istringstream& instr, std::ostringstream& outstr, std::vector<std::string> entry)
{
	int index = 0;
	std::string word;
	std::string leftovers;
	while (instr >> word)
	{
		if(word.size() >= 3)
		{
			if (word[0] == '|' && word[2] == '|')
			{
				index = get_index_and_leftovers(word, leftovers);
				outstr << entry[index] << leftovers << " ";
			}
			else
			{
				outstr << word << " ";
			}
		}
		else
		{
			outstr << word << " ";
		}
		
	}
}



void write_junk_mail(std::istream& DB, std::istream& temp, std::string junkMailName)
{
	std::string fullName;
	std::ofstream outputFile;
	std::vector<std::vector<std::string>> dbEntries;
	std::vector<std::string> entry;
	std::string line;
	std::string word;
	char ch;

	while (std::getline(DB, line))
	{
		std::istringstream instr(line);
		entry.clear();
		while (get_next_entry(instr, word))
		{
			entry.push_back(word);
		}
		dbEntries.push_back(entry);
	}

	for (int i = 0; i < dbEntries.size(); i++)
	{
		// Reset the template stream so we can write a new email
		temp.clear();
		temp.seekg(0, temp.beg);
		
		
		fullName = junkMailName.substr(0, junkMailName.size() - 4) + std::to_string(static_cast<long long>(i)) + junkMailName.substr(junkMailName.size() - 4, 4);
		outputFile.open(fullName);
		if (outputFile.fail())
		{
			file_read_error(junkMailName);
		}

		while (std::getline(temp, line))
		{
				std::istringstream instr(line);
				std::ostringstream outstr;
				replace_signifiers(instr, outstr, dbEntries[i]);
				outputFile << outstr.str() << "\n";
		}
		outputFile.close();
	}

}

int main(int argc, char* argv[])
{
	// Checks for correct number of parameters
	if (argc != 4)
	{
		usage(argv[0]);
	}


	std::ifstream DBFile;
	std::ifstream templateFile;

	DBFile.open(std::string(argv[1]).c_str());
	if (DBFile.fail())
	{
		file_read_error(std::string(argv[1]));
	}
	templateFile.open(std::string(argv[2]).c_str());
	if (templateFile.fail())
	{
		file_read_error(std::string(argv[2]));
	}
	std::string outputFileName = std::string(argv[3]).c_str();
	

	write_junk_mail(DBFile, templateFile, outputFileName);

	DBFile.close();
	templateFile.close();

	return 0;
}