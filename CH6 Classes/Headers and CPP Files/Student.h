#include "stdafx.h"
#include "Grade.h"
#include <string>

using namespace std;

class Student
{
public:
	/**
		Default Constructor
	*/
	Student();

	/**
		Constructor with the student's name given
		@param name string with the student's name
	*/
	Student(string n);

	/**
		Adds a quiz score to the 
		@param score double score to be added to the total
	*/
	void add_quiz(double score);

	/**
		Adds a grade for gpa calculation
	*/
	void add_grade(string grade);

	/**
		returns the name of the student
		@return name string name of the student
	*/
	string get_name() const;

	/**
		returns the total points on quizzes
		@return quiz_total double total accumulated quiz points
	*/
	double get_total_score() const;

	/**
		computes are returns the average score on a quiz
		@return average double the average quiz score
	*/
	double get_average_score() const;

	/**
		returns the current gpa
	*/
	double get_gpa() const;

private:
	Grade grade;
	string name;
	double quiz_total;
	double grade_total;
	double num_quizzes;
	double num_grades;
	double gpa;
};