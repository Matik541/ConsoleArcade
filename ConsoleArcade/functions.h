#pragma once

#include <string>

/*
* repeat a string a specified number of times
*
* @param str	The string to repeat
* @param times	The number of times to repeat the string
*
* @return The repeated string
*/
inline std::string repeat(std::string str, int times)
{
	std::string s1 = str;
	for (int i = 1; i < times; i++)
		s1 += str;
	return s1;
}

/*
* repeat an array of char a specified number of times
*
* @param c_str	The string to repeat
* @param times	The number of times to repeat the string
*
* @return The repeated string
*/
inline std::string repeat(const char* c_str, int times)
{
	std::string s1 = c_str;
	for (int i = 1; i < times; i++)
		s1 += c_str;
	return s1;
}

/*
* calculate a simple power of base to the exponent
*
* @param base		The base of the power
* @param exponent	The exponent of the power
*
* @return The result of the power
*/
inline int pow(int base, int exp)
{
	int sum = 1;
	while (exp-- > 0)
		sum *= base;
	return sum;
}
