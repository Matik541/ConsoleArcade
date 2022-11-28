#include "functions.h"

/*
* repeat a char a specified number of times
*
* @param chr	The character to repeat
* @param times	The number of times to repeat the string
*
* @return The repeated array of characters
*/
inline const char* repeat_char(char chr, int n)
{
	std::string s1 = std::to_string(chr);
	for (int i = 1; i < n; i++)
		s1 += chr;
	return s1.c_str();
}