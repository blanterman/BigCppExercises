/*	Exercise P11.5. Measure the speed difference between a statically bound 
call and a dynamically bound cal. Use the Time class to measure the time spent
in one loop of firtual function calls and another loop of regular function 
calls.

Bryson Lanterman 20190225
*/

#include "stdafx.h"

class SpeedTest
{
public:
	SpeedTest();
	void sLoop();
	virtual void vLoop();
};