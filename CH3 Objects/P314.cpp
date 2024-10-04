#include "ccc_win.h"
#include "ccc_empl.h"
#include <string>

using namespace std;

int ccc_win_main()
{
	string name1, name2, name3;
	double salary1 = 0.0, salary2 = 0.0, salary3 = 0.0;
	name1 = cwin.get_string("Enter name of first employee: ");
	salary1 = cwin.get_double("Enter salary of first employee: ");
	Employee e1(name1, salary1);

	Point p1(0, 1);
	Point p4(e1.get_salary(), 1);
	Line l1(p1, p4);
	Message m1(p1, e1.get_name());
	
	name2 = cwin.get_string("Enter name of second employee: ");
	salary2 = cwin.get_double("Enter salary of second employee: ");
	Employee e2(name2, salary2);

	Point p2(0, 2);
	Point p5(e2.get_salary(), 2);
	Line l2(p2, p5);
	Message m2(p2, e2.get_name());
	
	name3 = cwin.get_string("Enter name of third employee: ");
	salary3 = cwin.get_double("Enter salary of third employee: ");
	Employee e3(name3, salary3);

	Point p3(0, 3);
	Point p6(e3.get_salary(), 3);
	Line l3(p3, p6);
	Message m3(p3, e3.get_name());

	cwin.coord(-1,3.1,200000,0);
	cwin << l1 << l2 << l3 << m1 << m2 << m3;

	return 0;
}