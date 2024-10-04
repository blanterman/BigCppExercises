#include "stdafx.h"
#include "Country.h" //#include <string> is here
#include <iostream>

int main()
{
	bool cont = true; // flag for while loop
	Country c_area;
	Country c_pop;
	Country c_density;

	while(cont)
	{
		string choice, remainder;
		cout << "What would you like to do?\n"
			<< "(a) Add a country\n"
			<< "(p) Print results \n"
			<< "(q) quit \n\n";
		cin >> choice;
		getline(cin, remainder); // Remainder of line

		if(choice == "a")
		{
			string n;
			double pop = 0.0;
			double area = 0.0;
			cout << "What is the name of the country? ";
			getline(cin, n);
			cout << "\n\nWhat is the population of " << n << "? ";
			cin >> pop;
			cout << "\n\nWhat is the area of " << n << "? ";
			cin >> area;
			Country c(n, pop, area);
			getline(cin, remainder); // Remainder of line

			if(c.get_area() > c_area.get_area())
				c_area = c;
			if(c.get_population() > c_pop.get_population())
				c_pop = c;
			if(c.get_density() > c_density.get_density())
				c_density = c;
		}
		else if(choice == "p")
		{
			cout << "The country with the largest area is: " << c_area.get_name() << "\n"
				<< "The country with the largest population is: " << c_pop.get_name() << "\n"
				<< "The country with the largest density is: " << c_density.get_name() << "\n";
			cont = false;
		}
		else if(choice == "q")
			cont = false;
		else
		{
			cout <<"That was not a valid choice\n\n";
		}
	}
	return 0;
}