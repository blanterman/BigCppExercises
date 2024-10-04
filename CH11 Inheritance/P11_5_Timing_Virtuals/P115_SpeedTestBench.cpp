/*	Exercise P11.5. Measure the speed difference between a statically bound 
call and a dynamically bound cal. Use the Time class to measure the time spent
in one loop of firtual function calls and another loop of regular function 
calls.

Bryson Lanterman 20190225
*/

#include "stdafx.h"
#include "P115_VirtualVSStatic2.h"
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// Declaring timing variables
	LARGE_INTEGER frequency; // ticks per second
	LARGE_INTEGER t1, t2;
	double elapsedTimeS = 0;
	double elapsedTimeV = 0;
	vector<SpeedTest*> v1(1000);


	// Create the object to gain access to the functions
	SpeedTest s1;

	for (int j = 0; j < 500; j++)
	{
		v1[j] =  new SpeedTest();
	}
	for (int j = 500; j < 1000; j++)
	{
		v1[j] = new SpeedTest2();
	}

	

	//Time the static function
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t1);
	for (int j = 0; j < 1000; j++)
	{
		for (int i = 0; i < 1000; i++)
		{
			v1[i]->sLoop();
		}
	}
	QueryPerformanceCounter(&t2);
	elapsedTimeS = (t2.QuadPart-t1.QuadPart) * 1000.0 / frequency.QuadPart;

	cout << "1000000 calls to the static function took " << elapsedTimeS << " miliseconds\n";

	//Time the virtual function
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t1);
	for (int j = 0; j < 1000; j++)
	{
		for (int i = 0; i < 1000; i++)
		{
			v1[i]->vLoop();
		}
	}
	QueryPerformanceCounter(&t2);
	elapsedTimeS = (t2.QuadPart-t1.QuadPart) * 1000.0 / frequency.QuadPart;

	cout << "1000000 calls to the virtual function took " << elapsedTimeS << " miliseconds\n";

	return 0;
}