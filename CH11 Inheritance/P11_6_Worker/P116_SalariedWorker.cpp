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
#include "P116_SalariedWorker.h"

SalariedWorker::SalariedWorker()
	:Worker()
{

}

SalariedWorker::SalariedWorker(string n, double hourlyRate)
	: Worker(n, hourlyRate)
{

}

double SalariedWorker::compute_pay(int hours)
{
	return 40.0 * Worker::get_rate();
}