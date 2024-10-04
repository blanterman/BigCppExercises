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

class SalariedWorker : public Worker
{
public:
	/**
		Constructs a salaried worker object with no name or rate
	*/
	SalariedWorker();
	/**
		Constructs a salaried worker object with given name and rate
		@param n name of the salaried worker
		@param hourlyRate hourly rate of the salaried worker
	*/
	SalariedWorker(string n, double hourlyRate);
	/**
		Computes pay for the salaried worker
		@param hours hours worked for the week
		@return pay based on 40 hours of work regarless of hours
	*/
	virtual double compute_pay(int hours);
};