/*	Exercise P9.14. Write a program that asks the user to input a number n and
prints all permutations of the sequence of numbers 1, 2, 3, ..., n. For 
example, if n is 3, the program should print

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

Hint: Write a function

	permutation_helper(vector<int> prefix, vector<int> to_permute)

that computes all the permutations in the array to_permute and prints each 
permutation, prefixed by all numbers in the array prefix. For example, if 
prefix contains the number 2 and to_permute the numbers 1 and 3, then 
permutation_helper prints

2 1 3
2 3 1

The permutation_helper function does the following: If to_permute has no 
elements, print the elements in prefix. Otherwise, fir each element e in 
to_permute, make an array to_permute2 that is equal to permute except fo e and
an array prefix2 consisting of prefix and e. Then call permutation_helper with 
prefix2 and to_permute2.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/**
	Computes all the permutations in the array to_permute and prints each 
	permutation, prefixed by all numbers in the array prefix.
	@param prefix array of the prefix integers
	@param to_permute array of ints to be permuted
*/
void permutation_helper(vector<int> prefix, vector<int> to_permute)
{
	
	if (to_permute.empty())
	{
		for (int i = 0; i < prefix.size(); i++)
		{
			cout << prefix[i];
			if (i == prefix.size() - 1)
			{
				cout << "\n";
			}
		}
	}
	else
	{
		
		for (int i = 0; i < to_permute.size(); i++)
		{
			vector<int> to_permute2;
			vector<int> prefix2;

			for (int j = 0; j < to_permute.size(); j++)
			{
				if (to_permute[i] != to_permute[j])
				{
					to_permute2.push_back(to_permute[j]);
				}
			}

			for (int k = 0; k < prefix.size(); k++)
			{
				prefix2.push_back(prefix[k]);
			}
			prefix2.push_back(to_permute[i]);
			
			permutation_helper(prefix2, to_permute2);
		}
	}
}

/*  Test Harness  */
/*  Most of what is in this main() function could also be put into a function
	so that all of the pertinant steps for a permutation could be self 
	self contained. But this is just an exercise.
*/
int main()
{
	int n = 0;
	vector<int> to_permute;
	vector<int> prefix;
	cout << "enter a positive integer: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		to_permute.push_back(i + 1);
	}

	permutation_helper(prefix, to_permute);

	return 0;
}