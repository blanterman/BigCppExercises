/*	Exercise P12.11. Write a program that keeps an employee database in a 
random-access file. Implement functions for adding and removing employees. You
need not keep employees in sorted order. To remove an employee, just fill the 
entire record with spaces. When adding an employee, try to add it into one of 
those empty spots first before appending it to the end of the file.

Bryson Lanterman 20200211

This is far from a perfect implementation. Code repetition is bad, I am keeping 
track of the number of records and the number of spaces and keeping that all in
order seems nightmarish. Etc.
This implementation assumes that the data file has no initial lines of blank 
spaces. If there are, it will count them as entries.
It is possible to search for a blank name to remove. If there are blank lines, 
it will find them and remove them then update the number of entries. But since 
the deletion method is just putting in a bunch of spaces, the update is 
erroneous.
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "ccc_empl.h"

const int RECORD_SIZE = 30 + 10;

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
	Converts a string to a floating-point value, e.g.,
	"3.14" -> 3.14.
	@param s a string representing a floating-point value
	@return the equivalent floating-point value
*/
double string_to_double(std::string s)
{
	std::istringstream instr(s);
	double x;
	instr >> x;
	return x;
}

/**
	Raises an employee salary.
	@param e employee receiving raise
	@param percent the percentage of the raise
*/
void raise_salary(Employee& e, double percent)
{
	double new_salary = e.get_salary() * (1 + percent / 100.0);
	e.set_salary(new_salary);
}

/**
	Reads an employee record from a file.
	@param e filled with the employee
	@param in the stream to read from
*/
void read_employee(Employee& e, std::istream& in)
{
	std::string line;
	std::getline(in, line);
	if (in.fail()) return;
	std::string name = line.substr(0, 30);
	double salary = string_to_double(line.substr(30, 10));
	e = Employee(name, salary);
}

/**
	Writes an employee record to a stream.
	@param e the employee record to write
	@param out the stream to write to
*/
void write_employee(Employee e, std::ostream& out)
{
	out << e.get_name() << setw(10 + (30 - e.get_name().length()))
		<< fixed << setprecision(2)
		<< e.get_salary()
		<< "\n";
}


int main()
{
	std::cout << "Please enter the data file name to access: ";		// Asks the user for input
	// Get the name of the file
	std::string filename;
	std::getline(std::cin, filename);
	// Create a file stream with the file name
	std::fstream fs;
	fs.open(filename.c_str());
	fs.seekg(0, ios::end); /* go to end of file */
	
	// Adjust record size value for the new line length no matter what system you are on
	int nl_length = newline_length(fs);
	int adjusted_record_size = RECORD_SIZE + nl_length;
	int nrecord = fs.tellg() / adjusted_record_size;
	int nspaces = 0;												// Assumption that there are no blank entries

	// Database will be displayed initially
	int option = 1;
	
	// Initialize variables for using file stream and getting user input
	Employee current_employee;
	Employee e;
	int current_record = 0;
	std::string choice;
	std::string line;

	while(true)
	{
		if (option == 1) // Option 1 is viewing the entire data base 
		{
			std::cout << "\n" << filename << "\n";
			fs.seekg(0, ios::beg);
			if (fs.fail())
			{
				std::cout << "No data\n";
			}
			else
			{
				while(getline(fs, line))
				{
					std::cout << line << "\n";
				}
				fs.clear(); // Resets the eof fail status
				std::cout << nrecord << "\n";
			}

		}

		if (option == 2) // Option 2 is adding a record to the database
		{
			std::cout << "Please enter the name of the employee to add record: ";
			std::string name_input;
			std::getline(std::cin, name_input);
			
			// Buffer the name input with spaces so the length of the string is 30
			while (name_input.size() < 30)
			{
				name_input += " ";
			}

			double salary;
			std::cout << "Please enter the salary of the employee: ";
			std::string salary_input;
			std::getline(std::cin, salary_input);
			salary = string_to_double(salary_input);
			
			// Make an employee with the name and salary input
			current_employee = Employee(name_input, salary);
			
		
			current_record = -1;
			bool in_space = false;
			// Jump from record to record using the file stream to get the name, looking for spaces (Empty entry)
			for (int i = 0; i < nrecord + nspaces; i++)
			{
				fs.seekg(i * adjusted_record_size, ios::beg);
				read_employee(e, fs);
				if (e.get_name() == "                              ")// Empty entry found in the record
				{
					fs.seekg(i * adjusted_record_size, ios::beg);	// Put the get pointer back to the beginning of the record
					fs.seekp(fs.tellg(), ios::beg);					// Put the put pointer to where the get pointer is (the empty record)
					current_record = i;								// Updated to indicate an empty record was found and not appending to end of database
					nspaces--;										// Update number of blank entries in the database
					break;
				}
			}

			if (current_record == -1)								// No empty records were found, so place the put pointer at the end of the filestream
			{
				fs.seekp(0, ios::end);
			}

			write_employee(current_employee, fs);					// Write the record
			nrecord++;												// Update the number of records
		}

		if (option == 3) // Option 3 is deleting a record
		{
			// Get the name of employee to delete
			std::cout << "Please enter the name of the employee to remove from the database: ";
			std::string record_name;
			std::getline(std::cin, record_name);
			// Make the name have the same size as the entries in the data base
			while (record_name.size() < 30)
			{
				record_name += " ";
			}

			current_record = -1;
			// Jump from record to record, looking for a matching name
			for (int i = 0; i < nrecord + nspaces; i++)
			{
				fs.seekg(i * adjusted_record_size, ios::beg);
				read_employee(e, fs);

				if (e.get_name() == record_name)					// Found matching name
				{
					fs.seekg(i * adjusted_record_size, ios::beg);	// Go back to beginning of entry
					fs.seekp(fs.tellg(), ios::beg);					// Move put pointer to beginning of entry
					fs << "                                        \n";	// Delete entry by placing all spaces
					// Update numbers of full and empty entries
					nrecord--;		
					nspaces++;
					current_record = i;
					break;
				}
			}
			if (current_record == -1)
			{
				std::cout << "Could not find record.\n";
			}
		}
		
		// main menu for user
		std::cout << "\n\nWhat would you like to do now? Please please choose from list.\n"
			<< "(1) View the Data Base. \n"
			<< "(2) Add a Record to the Data Base. \n"
			<< "(3) Remove a Record from the Data Base. \n"
			<< "(99) quit.\n";

		// Get input from user
		std::getline(std::cin, choice);
		option = std::stoi(choice);

		if (option == 99)
		{
			return 0;
		}
		
	}

	// cleanup
	fs.close(); 
	return 0;
}