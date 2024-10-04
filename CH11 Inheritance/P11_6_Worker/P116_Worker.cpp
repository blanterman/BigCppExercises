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
#include "P116_Worker.h"

Worker::Worker()
{
	rate = 0.0;
}

Worker::Worker(string n, double hourlyRate)
{
	name = n;
	rate = hourlyRate;
}

double Worker::get_rate() const
{
	return rate;
}

string Worker::get_name() const
{
	return name;
}

double Worker::compute_pay(int hours)
{
	return 0.0 * static_cast<double>(hours);
}