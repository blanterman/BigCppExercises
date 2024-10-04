#include "ccc_win.h"

class Cannonball
{
public:

	/**
		Default Constructor
	*/
	Cannonball();

	/**
		Constructor with the weight and the initial x position provided
		@param weight floating point weight of the cannonball
		@param x floating point initial x position
	*/
	Cannonball(double weight, double x);

	/**
		Computes the new x and y positions using current positions and velocities
		then updates the y-velocity (x-velocity is constant)
		@param sec floating point time tha the cannonball is moving.
	*/
	void move(double sec);

	/**
		Plots the current position of the cannonball
	*/
	void plot() const;

	/**
		"shoots" the cannonball by continually calling move with a time of 0.1
		until the y-position is 0 or less, meaning the cannon ball has fallen 
		to the ground.
		@param alpha float of the initial angle the cannon is pointed
		@param init_v float of the initial velocity of the cannonball.
	*/
	void shoot(double alpha, double init_v);
private:
	double x_pos;
	double x_vel;
	double y_pos;
	double y_vel;
};