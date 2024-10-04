#include "stdafx.h"
#include "Student.h"

Student::Student()
{
	quiz_total = 0.0;
	num_quizzes = 0.0;
	grade_total = 0.0;
	num_grades = 0.0;
}

Student::Student(string n)
{
	name = n;
	quiz_total = 0.0;
	num_quizzes = 0.0;
	grade_total = 0.0;
	num_grades = 0.0;
}

void Student::add_quiz(double score)
{
	quiz_total += score;
	num_quizzes++;
}

void Student::add_grade(string g)
{
	Grade grade(g);
	grade_total += grade.convert();
	num_grades++;
}

string Student::get_name() const
{
	return name;
}

double Student::get_total_score() const
{
	return quiz_total;
}

double Student::get_average_score() const
{
	return quiz_total / num_quizzes;
}

double Student::get_gpa() const
{
	return grade_total / num_grades;
}
