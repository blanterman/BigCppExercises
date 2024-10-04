/*	Exercise P12.7. The program in Section 12.5 only locates one record and 
updates the salary. Write a program that raises or lowers the salaries of all 
employees by a given percentage.


*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

int main()
{
	std::cout << "Please enter the data file name to update all salaries in that file: ";
	std::string filename;
	std::cin >> filename;
	std::fstream fs;
	fs.open(filename.c_str());
	fs.seekg(0, ios::end); /* go to end of file */
	int nrecord = fs.tellg() / RECORD_SIZE;

	const double SALARY_CHANGE = 300.0;

	for (int pos = 0; pos <= nrecord; pos++)
	{
		Employee e;
		fs.seekg(pos * RECORD_SIZE, ios::beg);
		read_employee(e, fs);
		raise_salary(e, SALARY_CHANGE);
		fs.seekp(pos * RECORD_SIZE, ios::beg);
		write_employee(e, fs);
	}

	fs.close();
	return 0;
}