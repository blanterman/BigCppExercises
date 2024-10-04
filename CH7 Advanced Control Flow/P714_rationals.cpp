/*	Exercise P7.14
Program the following simulation: Darts are thrown at random points onto a
square with corners (1,1) and (-1,-1). If the dart lands inside the unti circle
(that is, the circle with center (0,0) and radius 1, it is a hit. Otherwise it 
is a miss. Run this simulation and use it to determine an approximate value for 
pi. Explain why this is a better method for estimating pi than the Buffon 
needle program.

Written by Bryson Lanterman 20180301
This is the version with internet help where only limited rational numbers are 
available by the random function.
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
	Sets a double variable to a random value between -1 and 1
*/

void pRandDbl (double& val)
{
	val = ((double)rand() * (1 - -1)) / (double)RAND_MAX + -1;
}

/**
	Sets a bool if a given coordinate is a hit. A hit is a coordinate that has a 
	distance from the origin of 1 or less.
	@param x double x coordinate
	@param y double y coordinate
*/
void verifyHit(bool& hit, double x, double y)
{
	double dist;
	dist = sqrt(x * x + y * y);
	hit = dist <= 1.0;
}

int main()
{
	double xCoord;
	double yCoord;
	srand(time(NULL));
	long trials = 100000;
	bool hit = false;
	long hitCount = 0;
	for(long i = 0; i < trials; i++)
	{
		xCoord = 0;
		yCoord = 0;
		pRandDbl(xCoord);
		pRandDbl(yCoord);
		verifyHit(hit, xCoord, yCoord);
		if(hit)
		{
			hitCount++;
		}
	}
	double approxPi = 4.0 * (double)hitCount / (double)trials;
	cout << "Pi is approximately: " << approxPi << endl;
	return 0;
}