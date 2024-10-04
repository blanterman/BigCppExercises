/*	Exercise P12.9. To find a particular employee in a database file, the 
program needs to search one record at a time. If the records are sorted, there 
is a faster way. Count the number of records in the file, by dividing the 
length of the file by the length of each record. Set a variable first to 1, 
last to nrecords. Compute mid = (first + last)/2. Read the record at mid. Maybe
you are luchy, and you actually found the record you wanted. If so, print it 
and exit. Is its name before or after the name that you are searching? Adjust 
either last to mid - 1 or first to mid + 1 and repeat the search. This 
searching method is called binary search, and it is much faster than a 
sequential search through all records. Implement this searching method.

Bryson Lanterman 20191209
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "ccc_empl.h"

const int NEWLINE_LENGTH = 2; /* or 1 on Unix */
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;

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
	getline(in, line);
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

/**
	Searches the database for the employee using a binary search method
	@param first beginning index to start looking
	@param last ending index to start looking
	@param nameIn of employee we are searching for
	@param in the stream to search
*/
int search_record_binary(int first, int last, std::string nameIn, std::istream& in)
{
	int employee_index = -1;
	int entry_to_check = (first + last) / 2;
	in.seekg(entry_to_check * RECORD_SIZE, ios::beg);
	std::string line;
	getline(in, line);
	if (in.fail()) return -1;
	std::string name = line.substr(0, 30);
	if (name == nameIn)
	{
		return entry_to_check;
	}
	if (first == last)
	{
		return employee_index;
	}
	if (nameIn < name)
	{
		employee_index = search_record_binary(first, entry_to_check - 1, nameIn, in);
	}
	if (nameIn > name)
	{
		employee_index = search_record_binary(entry_to_check + 1, last, nameIn, in);
	}
	return employee_index;
}


int main()
{
	std::cout << "Please enter the data file name to access: ";
	std::string filename;
	std::getline(std::cin, filename);
	std::fstream fs;
	fs.open(filename.c_str());
	fs.seekg(0, ios::end); /* go to end of file */
	int nrecord = fs.tellg() / RECORD_SIZE;

	const double SALARY_CHANGE = 5.0;
	int option = 3;
	Employee current_employee;
	Employee e;
	int current_record = 0;
	std::string choice;

	while(true)
	{
		if (option == 1) // Option 1 is raising the salary by the standard percent 
		{
			std::cout << "Raising " << current_employee.get_name() << "\'s salary by " << SALARY_CHANGE <<  "%\n";
			raise_salary(current_employee, SALARY_CHANGE);
			fs.seekp(current_record * RECORD_SIZE, ios::beg);
			write_employee(current_employee, fs);
			std::cout << current_employee.get_name() << "\n"
				<< current_employee.get_salary() << "\n";
		}

		if (option == 2) // Option 2 is viewing the next record on the list
		{
			if (current_record == nrecord - 1)
			{
				current_record = 0;
			}
			else
			{
				current_record++;
			}
			fs.seekg(current_record * RECORD_SIZE, ios::beg);
			read_employee(current_employee, fs);
			std::cout << current_employee.get_name() << "\n"
				<< current_employee.get_salary() << "\n";
		}

		if (option == 3) // Option 3 is selecting a record to view
		{
			std::cout << "Please enter the name of the employee to view record: ";
			std::string record_name;
			std::getline(std::cin, record_name);

			while (record_name.size() < 30)
			{
				record_name += " ";
			}
			current_record = -1;
			current_record = search_record_binary(0, nrecord - 1, record_name, fs);
			if (current_record != -1)
			{
				fs.seekg(current_record * RECORD_SIZE, ios::beg);
				read_employee(e, fs);
				current_employee = e;
				std::cout << current_employee.get_name() << "\n"
					<< current_employee.get_salary() << "\n";
			}
			if (current_record == -1)
			{
				std::cout << "Could not find record.\n";
				std::cout << current_employee.get_name() << "\n"
						<< current_employee.get_salary() << "\n";
			}
		}

		std::cout << "What would you like to do now? Please please choose from list.\n"
			<< "(1) Change the salary of this record. \n"
			<< "(2) View the next record. \n"
			<< "(3) Find another employee. \n"
			<< "(99) quit.\n";

		std::getline(std::cin, choice);
		option = std::stoi(choice);

		if (option == 99)
		{
			return 0;
		}
		
	}
	fs.close();
	return 0;
}