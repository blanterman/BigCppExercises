/*	Write a base class Worker and derived classes HourlyWorker and 
SalariedWorker. Every worker has a name and a salary rate. Write a virtual 
function compute_pay(int hours) that computes the weekly pay for every worker. 
An hourly worker gets paid the hourly wage for the actual number of hours 
worked, if hours is at most 40. If the hourly worker worked more than 40 hours,
the excess is paid at time and a half. The salaried worker gets paid the hourly
wage for 40 hours, no matter what the actual number of hours is.

Bryson Lanterman 20190228
*/
#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Worker
{
public:
	/**
		Constructs a Worker with empty name and no rate
	*/
	Worker();
	/**
		Constructs a worker with a name and an hourly rate
		@param n name of worker
		@param hourlyRate hourly rate for worker
	*/
	Worker(string n, double hourlyRate);
	/**
		Returns rate of Worker
		@return rate rate of work for the worker
	*/
	double get_rate() const;
	/**
		Returns the name of the worker
		@return name name of the worker
	*/
	string get_name() const;
	/**
		Computes and returns the weekly pay for the worker
		@param hours hours the worker worked in the week
		@return pay the amout owed to the worker for the week
	*/
	virtual double compute_pay(int hours);
private:
	string name;
	double rate;
};