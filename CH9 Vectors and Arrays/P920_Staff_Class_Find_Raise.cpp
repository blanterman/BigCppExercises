/*	Exercise P9.20. Define a class

class Staff
{
public:
	. . .
private:
	vector<Employee> members;
};

and implement the find and raise_salary procedures for the Staff data type.


Bryson Lanterman 20180919
*/

#include "stdafx.h"
#include "P920_Staff.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main ()
{
	vector<P920_Employee> members(5);
	members[0] = P920_Employee("A", 1000);
	members[1] = P920_Employee("B", 2000);
	members[2] = P920_Employee("C", 3000);
	members[3] = P920_Employee("D", 4000);
	members[4] = P920_Employee("E", 5000);
	P920_Staff staff = members;

	vector<P920_Employee> testBatch = staff.find_salaries_between(2000, 4000);

	for (int i = 0; i < testBatch.size(); i++)
	{
		cout << testBatch[i].get_name() << "\n";
	}
	cout << "\n";

	P920_Employee newEmployee("F", 2500);
	staff.add_employee(newEmployee);

	vector<P920_Employee> testBatch2 = staff.find_salaries_between(2000, 4000);

	for (int i = 0; i < testBatch2.size(); i++)
	{
		cout << testBatch2[i].get_name() << "\n";
	}
	cout << "\n";

	staff.raise_salary(staff.get_employee_index("A"), 130);

	vector<P920_Employee> testBatch3 = staff.find_salaries_between(2000, 4000);

	for (int i = 0; i < testBatch3.size(); i++)
	{
		cout << testBatch3[i].get_name() << "\n";
	}
	cout << "\n";

	return 0;
}