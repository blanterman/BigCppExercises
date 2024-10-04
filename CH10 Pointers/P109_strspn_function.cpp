/*	Exercise P10.9. Implement the standard library function

int strspn(const char s[], const char t[])

that returns the length of the prefix of s consisting of characters in t (in any order)

*/

#include "stdafx.h"

using namespace std;

/**
	returns the length of the prefix of s consisting of characters in t (in any order)
	@param s character array to be scanned
	@param t character array containing the characters to be matched
	@return quant integer length of the prefix of s consisting of the characters in t (in any order)
*/
int strspn(const char s[], const char t[])
{
	int quant = 0;
	bool found = true;
	char currs = *s;	//could use s[0]
	char currt = *t;	//could use t[0]
	int i = 0;
	int j = 0;
	while (found == true)
	{
		j = 0;
		currt = *(t + j);	//could use t[j]
		found = false;
		while (currt != '\0' && found == false)
		{
			if (currs == currt)
			{
				quant++;
				found = true;
			}
			j++;
			currt = *(t + j);	//could use t[j]
		}
		i++;
		currs = *(s + i);	//could use s[i]
	}
	return quant;
}

int main()
{
	char s[] = "12398767645654234554356a98bc";
	char t[] = "123456789";
	int num = strspn(s, t);
	printf("%d\n", num);
	return 0;
}

