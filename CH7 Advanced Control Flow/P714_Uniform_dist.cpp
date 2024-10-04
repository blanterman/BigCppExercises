/*	Exercise P7.14
Program the following simulation: Darts are thrown at random points onto a
square with corners (1,1) and (-1,-1). If the dart lands inside the unti circle
(that is, the circle with center (0,0) and radius 1, it is a hit. Otherwise it 
is a miss. Run this simulation and use it to determine an approximate value for 
pi. Explain why this is a better method for estimating pi than the Buffon 
needle program.

Written by Bryson Lanterman 20180301
This is the version with <random> used to get random doubles from a uniform dist.
*/

#include "stdafx.h"
#include <iostream>
#include <random>

using namespace std;

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
	long trials = 1000000;
	bool hit = false;
	long hitCount = 0;
	
	random_device rd; //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd());//Standard mersenne_twister_engine seeded with rd()
	uniform_real_distribution<> dis(-1.0, 1.0);
	
	for(long i = 0; i < trials; i++)
	{
		//Use dis to transform the random unsigned int generated by gen into a double in [-1, 1)
		xCoord = dis(gen);//Each call to dis(gen) generates a new random double
		yCoord = dis(gen);//Each call to dis(gen) generates a new random double
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