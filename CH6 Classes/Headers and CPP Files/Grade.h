#include "stdafx.h"
#include <string>

using namespace std;

class Grade
{
public:
	/**
		Default constructor
	*/
	Grade();

	/**
		Constructor given the grade
		@param g string grade
	*/
	Grade(string g);

	/**
		Returns a converted grade to a point value
	*/
	double convert() const;
private:
	string grade;
};
