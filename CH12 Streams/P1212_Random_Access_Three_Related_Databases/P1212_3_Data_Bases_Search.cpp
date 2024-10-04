/*	Exercise P12.12. Write a program that manipulates three database files. The 
fisrt file contains the names and telephone numbers of a group of people. The 
second file contains the names and Social Security numbers of a group of people.
The third file contains the Social Security numbers and annual salaries of a 
group of people. The groups of people should overlap but need not be completely 
identical. Your program should ask the user for a telephone number and then 
print the name, Social Security number, and annual income if it can determine 
that information.

Bryson Lanterman 20200226

This program uses the files: names_telephone.dat, names_ss.dat, and ss_sal.dat.
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

const int NAME_SS_RECORD_SIZE = 30 + 11;
const int NAME_TELE_RECORD_SIZE = 30 + 12;
const int SS_SAL_RECORD_SIZE = 11 + 10;

class employee
{
public:
	/**
		Default Constructor
	*/
	employee()
	{
		name = "                              ";
		social = "           ";
		salary = "          ";
		telephone = "            ";
	}

	/**
		Constructor of an employee object
		@param std::string n name of the employee
		@param std::string ss social security number of the employee
		@param std::string sal salary of the employee
		@param std::string tele telephone number of the employee
	*/
	employee(std::string n, std::string ss, std::string sal, std::string tele)
	{
		name = n;
		social = ss;
		salary = sal;
		telephone = tele;
	}

	/**
		Returns the name of the employee
		@return std::string name of the employee
	*/
	std::string get_name()
	{
		return name;
	}

	/**
		Returns the social security number of the employee
		@return std::string Social Security number of the employee
	*/
	std::string get_social()
	{
		return social;
	}

	/**
		Returns the salary of the employee
		@return std::string annual salary of the employee
	*/
	std::string get_salary()
	{
		return salary;
	}

	/**
		Returns the name of the employee
		@return std::string telephone number of the employee
	*/
	std::string get_telephone()
	{
		return telephone;
	}

	/**
		Sets the name of the employee
		@param std::string n name of the employee
	*/
	void set_name(std::string n)
	{
		name = n;
	}

	/**
		Sets the Social Security number of the employee
		@param std::string ss Social Security number of the employee
	*/
	void set_social(std::string ss)
	{
		social = ss;
	}

	/**
		Sets the salary of the employee
		@param std::string sal annual salary of the employee
	*/
	void set_salary(std::string sal)
	{
		salary = sal;
	}

	/**
		Sets the telephone number of the employee
		@param std::string tele telephone number of the employee
	*/
	void set_telephone(std::string tele)
	{
		telephone = tele;
	}

	/**
		Prints out the employee's information
	*/
	void print_info()
	{
		std::cout << "name: " << name << "\n"
			<< "telephone: " << telephone << "\n"
			<< "social: " << social << "\n"
			<< "salary: " << salary << "\n";
	}
private:
	std::string name;
	std::string social;
	std::string salary;
	std::string telephone;
};

/**
	Determines the newline character length by parsing the file
	@param fs reference to a file stream
	@return nl_length integer length of the newline character
*/
int newline_length(std::fstream& fs)
{
	int nl_length = 0;												// Initialize return variable
	char current_char;												// Character place holder for parsing
	long previous_position = 0;										// position of previously parsed character
	long current_position = 0;										// position of the current character being parsed
	long original_get_position = fs.tellg();						// position of the original get position before the function was called
	fs.seekg(0, std::ios::beg);										// go to the beginning of the file
	while (fs.get(current_char))									// Iterate through the file one character at a time
	{
		if (current_char == '\n')									// if we find a newline character
		{
			current_position = fs.tellg();							// update the current position so we can find out how far it it from the previous character
			nl_length = current_position - previous_position;		// character width of the new line character
			fs.seekg(original_get_position, std::ios::beg);			// Replace get position to where it was before the function was called
			return nl_length;										// Return the width of the newline character
		}
		previous_position = fs.tellg();								// since the character didn't match, update previous position 
	}

	return 0;														// If all else fails return 0
}


/**
	Populates name and telephone information after reading a file record
	@param e employee object to populate
	@param ntelin the stream to read from
*/
void read_employee_name_and_tele(employee& e, std::istream& ntelin)
{
	std::string line;
	std::getline(ntelin, line);
	if (ntelin.fail()) return;
	std::string name = line.substr(0, 30);
	std::string telephone = line.substr(30, 12);
	e.set_name(name);
	e.set_telephone(telephone);
}

/**
	Populates name and social information after reading a file record
	@param e employee object to populate
	@param nssin the stream to read from
*/
void read_employee_social(employee& e, std::istream& nssin)
{
	std::string line;
	std::getline(nssin, line);
	if (nssin.fail()) return;
	std::string name = line.substr(0, 30);
	std::string social = line.substr(30, 11);
	e.set_name(name);
	e.set_social(social);
}

/**
	Populates social and salary information after reading a file record
	@param e employee object to populate
	@param sssalin the stream to read from
*/
void read_employee_salary(employee& e, std::istream& sssalin)
{
	std::string line;
	std::getline(sssalin, line);
	if (sssalin.fail()) return;
	std::string social = line.substr(0, 11);
	e.set_social(social);
	std::string salary = line.substr(11, 10);
	e.set_salary(salary);
}

int main()
{
	std::cout << "Initializing Databases...\n";
	
	// Set database file names
	std::string name_ss_filename = "names_ss.dat";
	std::string name_telephone_filename = "names_telephone.dat";
	std::string social_salary_filename = "ss_sal.dat";

	// Create file streams for each file
	std::fstream nssfs;
	std::fstream ntelefs;
	std::fstream sssalfs;

	// open file streams for use
	nssfs.open(name_ss_filename.c_str());
	ntelefs.open(name_telephone_filename.c_str());
	sssalfs.open(social_salary_filename.c_str());

	// Place get pointer at end of each file to determine length
	nssfs.seekg(0, std::ios::end);
	ntelefs.seekg(0, std::ios::end);
	sssalfs.seekg(0, std::ios::end);

	// Find new line length
	int nl_length = newline_length(nssfs);

	// use new line length to adjust usable record size
	int adj_name_ss_record_size = NAME_SS_RECORD_SIZE + nl_length;
	int adj_name_tele_record_size = NAME_TELE_RECORD_SIZE + nl_length;
	int adj_ss_sal_record_size = SS_SAL_RECORD_SIZE + nl_length;

	// Determing the number of records in each file
	int nnssrecord = nssfs.tellg() / adj_name_ss_record_size;
	int nntelerecord = ntelefs.tellg() / adj_name_tele_record_size;
	int nsssalrecord = sssalfs.tellg() / adj_ss_sal_record_size;

	// Initialize employee objects
	employee e;
	employee found_e;

	while(true)
	{
		// reset employee objects using default constructor
		e = employee();
		found_e = employee();

		// ask user for a phone number and put phone number into memory
		std::cout << "Please input a phone number using the format XXX-XXX-XXXX : \n";
		std::string user_input;
		std::getline(std::cin, user_input);

		// Use phone number to find the name of the employee if there is a match
		ntelefs.seekg(0, std::ios::beg);
		if (ntelefs.fail()) // make sure the file has data
		{
			std::cout << "Name and telephone database contains no records\n";
			break;
		}
		else
		{
			//search the data in the file record by record
			for (int i = 0; i < nntelerecord; i++)
			{
				ntelefs.seekg(i * adj_name_tele_record_size, std::ios::beg);
				read_employee_name_and_tele(e, ntelefs);
				if (e.get_telephone() == user_input)
				{
					found_e.set_name(e.get_name());
					found_e.set_telephone(e.get_telephone());
					i = nntelerecord;
				}
			}
		}
		
		// The name will be the default if the whole file was checked with no 
		// match found.
		if (found_e.get_name() == "                              ")
		{
			std::cout << "No name matched that phone number\n";
			break;
		}

		// Use the name that was just found to find the Social Security Number
		nssfs.seekg(0, std::ios::beg);
		if (nssfs.fail()) // Make sure the file has data
		{
			std::cout << "Name and social database contains no records.\n";
			found_e.print_info();
			break;
		}
		else
		{
			// Search the file record by record for a match
			for (int i = 0; i < nnssrecord; i++)
			{
				nssfs.seekg(i * adj_name_ss_record_size, std::ios::beg);
				read_employee_social(e, nssfs);
				if (e.get_name() == found_e.get_name())
				{
					found_e.set_social(e.get_social());
					i = nnssrecord;
				}
			}
		}
		
		// If no match found, inform user, print what information there is
		if (found_e.get_social() == "           ")
		{
			std::cout << "No social security number matched the found name.\n Stopping search.\n";
			found_e.print_info();
			break;
		}

		// Use the social security number to find a salary for the employee
		sssalfs.seekg(0, std::ios::beg);
		if (sssalfs.fail()) // make sure the file doesn't not have data
		{
			std::cout << "Social and Salaray database contains no information.\n";
			found_e.print_info();
			break;
		}
		else
		{
			// Search the file record by record for a match
			for (int i = 0; i < nsssalrecord; i++)
			{
				sssalfs.seekg(i * adj_ss_sal_record_size, std::ios::beg);
				read_employee_salary(e, sssalfs);
				if (e.get_social() == found_e.get_social())
				{
					found_e.set_salary(e.get_salary());
					i = nsssalrecord;
				}
			}
		}

		// If no match was found, inform the user and print current level of 
		// information
		if (found_e.get_salary() == "          ")
		{
			std::cout << "No Salary information matched the found social security information, or the salary data was empty\n";
			found_e.print_info();
			break;
		}

		// If all information was found, print all information for the user
		found_e.print_info();

	}

	// cleanup
	nssfs.close();
	ntelefs.close();
	sssalfs.close();
	
	return 0;

}