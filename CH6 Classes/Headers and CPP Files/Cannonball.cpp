#include "ccc_win.h"
#include "Cannonball.h"

const double G = -9.8;
const double DEL_T = 0.1;
const double PI = 3.14159265358979323;
const double D2R = PI / 180;

Cannonball::Cannonball()
{
	x_pos = 0.0;
	x_vel = 0.0;
	y_pos = 0.0;
	y_vel = 0.0;
}

Cannonball::Cannonball(double weight, double x)
{
	double w = weight;
	x_pos = x;
	x_vel = 0.0;
	y_pos = 0.0;
	y_vel = 0.0;
}

void Cannonball::move(double sec)
{
	x_pos += (x_vel * sec);
	y_pos += (y_vel * sec);
	y_vel += G * sec;
}

void Cannonball::plot() const
{
	cwin << Point(x_pos, y_pos);
}

void Cannonball::shoot(double alpha, double init_v)
{

	x_vel = init_v * cos(alpha * D2R);
	y_vel = init_v * sin(alpha * D2R);


	do
	{
		plot();
		move(DEL_T);
	}
	while(y_pos > 0.0);

	plot();

}