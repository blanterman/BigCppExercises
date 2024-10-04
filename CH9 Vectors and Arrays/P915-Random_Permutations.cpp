/*	Exercise P9.15. Write a program that produces ten random permutations of 
the numbers 1 to 10. To generate a random permutation, you need to fill a 
vector with the numbers 1 to 10 so that no two entries of the vector have the 
same contents. You could do it by brute force, by calling rand_int until it 
produces a value that is not yet in the vector. Instead, you shouold implement
a smart method. Make a second array and fill it with the numbers 1 to 10. then
pick one of those at random, remove it, and append it to the permutations 
vector. Repeat ten times.

Bryson Lanterman 20180720
*/

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

/**
	Produces a random permutation of the values in a vector
	Note, must seed rand() before running this function
	@param v vector with the values to randomly permute
	@return permuted vector with the permuted values
*/
vector<int> random_permutation(const vector<int>& v)
{
	vector<int> vCopy = v;
	vector<int> permuted(v.size());
	for (int i = 0; i < v.size(); i++)
	{
		int randIndex = rand() % vCopy.size();
		permuted[i] = vCopy[randIndex];
		vCopy.erase(vCopy.begin() + randIndex);
	}
	return permuted;
}


int main()
{
	// Create and populate a vector with the values 1 to 10.
	vector<int> oneToTen(10);
	for(int i = 1; i <=10; i++)
	{
		oneToTen[i - 1] = i;
	}
	srand(time(NULL));

	//
	// Use the oneToTen vector to get ten random permutations of the numbers
	//1 to 10
	//
	vector<int> permuted(oneToTen.size());
	for (int i = 0; i < 10; i++)
	{
		
		permuted = random_permutation(oneToTen);
		for (int j = 0; j < permuted.size(); j++)
		{
			cout << permuted[j] << " ";
		}
		cout << "\n";
	}
}