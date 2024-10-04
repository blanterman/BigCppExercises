#include <string>

using namespace std;

class Person
{
public:
	/**
		Constructs a person with an empty name and age of 0.
	*/
	Person();

	/**
		Constructs a person with a given name but unknown age.
	*/
	Person(string pname);

	/**
		Constructs a person with a given name and a given age.
	*/
	Person(string pname, int page);

	/**
		Gets the name of the person by printing it out
	*/
	string get_name() const;

	/**
		Gets the name of the person by printing it out
	*/
	int get_age() const;
private:
	string name;
	int age; /* 0 if unknown */
};
