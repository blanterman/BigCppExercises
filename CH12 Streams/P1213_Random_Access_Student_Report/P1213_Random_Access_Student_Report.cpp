/*	Exercise P12.13. Write a program that prints out a student grade report. 
There is a file, classes.txt, that contains the names of all classes taught at a
college, such as

File classes.txt
1 CSC1
2 CSC2
3 CSC46
4 CSC151
5 MTH121
6 . . .

For each class, there is a file with student numbers and grades:

File csc2.txt
1 11234 A-
2 12547 B
3 16753 B+
4 21886 C
5 . . . 

Wirte a program that asks for a student ID and prints out a grade report for 
that student, by searching all class files. Here is a sample report

	Student ID 16763
	CSC2 B+
	MTH121 C+
	CHN1 A
	PHY50 A-

Bryson Lanterman 20200226

This program uses the files: 
- classes.txt
- BIO105.txt
- BIO205.txt
- CSC143.txt
- ECE380.txt
- ECE445.txt
- MTH121.txt
- MTH201.txt

*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

const int CLASSES_RECORD_SIZE = 6;
const int CLASS_RECORD_SIZE = 5 + 2;

class grade_entry
{
public:
	/**
		Default Constructor
	*/
	grade_entry()
	{
		id = "     ";
		grade = "  ";
	}

	/**
		Returns the id of the student that has the grade
		@return id id of the student that has the grade
	*/
	std::string get_id()
	{
		return id;
	}

	/**
		Returns the grade of the student
		@return grade the grade of the student
	*/
	std::string get_grade()
	{
		return grade;
	}

	/**
		Sets the grade_entry objects id parameter
		@parameter ident id number of the student with the grade
	*/
	void set_id(std::string ident)
	{
		id = ident;
	}

	/**
		Sets the grade_entry objects grade parameter
		@parameter g grade of the student
	*/
	void set_grade(std::string g)
	{
		grade = g;
	}
private:
	std::string id;
	std::string grade;
};

class student
{
public:
	/**
		Default Constructor
	*/
	student()
	{
		id = "     ";
	}

	/**
		Constructor of an student object
	*/
	student(std::string ident, std::vector<std::string> classes_vec, std::vector<std::string> grades_vec)
	{
		id = ident;
		classes = classes_vec;
		grades = grades_vec;
	}

	/**
		Returns the name of the student
		@return std::string id of the student
	*/
	std::string get_id()
	{
		return id;
	}

	/**
		Returns the classes vector of the student
		@return std::vector<std::string> classes of the student
	*/
	std::vector<std::string> get_classes()
	{
		return classes;
	}

	/**
		Returns the grades vector of the student
		@return std::vector<std::string> grades of the student
	*/
	std::vector<std::string> get_grades()
	{
		return grades;
	}

	/**
		Sets the id of the student
		@param std::string ident id of the student
	*/
	void set_id(std::string ident)
	{
		id = ident;
	}

	/**
		Adds a class with its grade to the students lists of classes and grades
		@param std::string class_to_add class to add to the classes list
		@param std::string grade_to_add grade to add to the grade list
	*/
	void add_class_and_grade(std::string class_to_add, std::string grade_to_add)
	{
		classes.push_back(class_to_add);
		grades.push_back(grade_to_add);
	}

	/**
		Prints out the student's report
	*/
	void print_info()
	{
		std::cout << "Student ID " << id << "\n";
		for (int i = 0; i < classes.size(); i++)
		{
			std::cout << classes[i] << " " << grades[i] << "\n";
		}
	}
private:
	std::string id;
	std::vector<std::string> classes;
	std::vector<std::string> grades;
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
	Populates id and grade information after reading a file record
	@param g grade_entry object to populate
	@param classin the stream to read from
*/
void read_student_grade(grade_entry& g, std::istream& classin)
{
	std::string line;
	std::getline(classin, line);
	if (classin.fail()) return;
	std::string id = line.substr(0, 4);
	std::string grade = line.substr(5, 2);
	g.set_id(id);
	g.set_grade(grade);
}



int main()
{
	std::cout << "Please enter a student's id to print report: \n";
	std::string student_id;
	std::getline(std::cin, student_id);

	// create and open filestream for the classes to check
	std::string classes_filename = "classes.txt";
	std::fstream classesfs;
	classesfs.open(classes_filename.c_str());

	// place get pointer at end of classes file to determine length
	classesfs.seekg(0, std::ios::end);

	// Find new line length
	int nl_length = newline_length(classesfs);

	// use new line length to adjust usable record size
	int adj_classes_record_size = CLASSES_RECORD_SIZE + nl_length;
	int adj_class_record_size = CLASS_RECORD_SIZE + nl_length;

	// Determing the number of records in class file
	int nclasses = classesfs.tellg() / adj_classes_record_size;

	// Initialize variables
	std::string className;	
	std::string classFileName;
	std::string line;
	std::fstream classfs;
	int nstudents = 0;
	
	// Initialize objects to be used
	student s = student();
	grade_entry g;
	
	s.set_id(student_id);

	// Look through all the classes for for the student's grade
	for (int i = 0; i < nclasses; i++)
	{
		// Initialize grade object
		g = grade_entry();
		// Move getter to next class record
		classesfs.seekg(i * adj_classes_record_size, std::ios::beg);
		// Read in the name of the next class
		std::getline(classesfs, line);
		className = line.substr(0, 6);
		// Change the class name to a class file name
		classFileName = className + ".txt";
		// Create and open the classes file stream
		classfs.open(classFileName.c_str());
		// Get the number of students in the class
		classfs.seekg(0, std::ios::end);
		nstudents = classfs.tellg() / adj_class_record_size;
		
		// Look through all the students
		for (int j = 0; j < nstudents; j++)
		{
			// move the getter to the next record
			classfs.seekg(j * adj_class_record_size, std::ios::beg);
			// populate the grade object with the current id and grade
			read_student_grade(g, classfs);
			// check if the current grade object's id matches the query
			if (g.get_id() == (s.get_id()))
			{
				// Add the class and the grade to the students data
				s.add_class_and_grade(className, g.get_grade());
				j = nstudents;
			}
		}
		// cleanup
		classfs.close();
	}

	// If after checking all the classes, none have been added to the student's
	// list of classes, then the student wasn't found. Inform the user
	if (s.get_classes().empty())
	{
		std::cout << "Student not found\n";
	}
	
	// Print the student's report
	s.print_info();

	// cleanup
	classesfs.close();
	return 0;

}