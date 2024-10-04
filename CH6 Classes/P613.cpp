// This is P614 also

#include "stdafx.h"
#include "Student.h"
#include <iostream>

int main()
{
	Student bryson("Bryson Lanterman");
	
	bryson.add_grade("A");
	bryson.add_grade("B+");
	bryson.add_grade("A-");
	bryson.add_grade("C");

	cout << bryson.get_name() << " has a gpa of: " << bryson.get_gpa() << "\n\n";

	bryson.add_quiz(100);
	bryson.add_quiz(65);
	bryson.add_quiz(70);
	bryson.add_quiz(85);
	bryson.add_quiz(100);

	cout << bryson.get_name() << " has earned " << bryson.get_total_score() 
		<< " total points on quizzes \nand has an average quiz score of " 
		<< bryson.get_average_score() << "\n\n";

	return 0;
}