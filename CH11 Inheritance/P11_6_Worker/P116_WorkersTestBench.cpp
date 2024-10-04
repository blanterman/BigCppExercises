/*	Write a base class Worker and derived classes HourlyWorker and
SalariedWorker. Every worker has a name and a salary rate. Write a virtual
function compute_pay(int hours) that computes the weekly pay for every worker.
An hourly worker gets paid the hourly wage for the actual number of hours
worked, if hours is at most 40. If the hourly worker worked more than 40 hours,
the excess is paid at time and a half. The salaried worker gets paid the hourly
wage for 40 hours, no matter what the actual number of hours is.

Bryson Lanterman 20190228
*/
#include "stdafx.h"
#include "P116_HourlyWorker.h"
#include "P116_SalariedWorker.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<Worker*> workers(6);
	workers[0] = new Worker("Bryson Lanterman", 50.0);
	workers[1] = new Worker("Shannon Lanterman", 100.0);
	workers[2] = new HourlyWorker("Matthew Lanterman", 10.0);
	workers[3] = new HourlyWorker("Evangeline Lanterman", 10.0);
	workers[4] = new SalariedWorker("Jane Lanterman", 10.0);
	workers[5] = new SalariedWorker("Baby4 Maybe", 10.0);

	for (int i = 0; i < workers.size(); i++)
	{
		cout << "Worker Name: " << workers[i]->get_name() << "\n"
			<< "Worker Rate: " << workers[i]->get_rate() << "\n"
			<< "Pay for 60 hrs: $" << workers[i]->compute_pay(60) << "\n\n";
	}
	return 0;
}