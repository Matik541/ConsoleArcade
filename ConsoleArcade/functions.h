#pragma once

#include <string>

std::string repeat(std::string s, int n)
{
	std::string s1 = s;
	for (int i = 1; i < n; i++)
		s += s1;
	return s;
}

int pow(int base, int n)
{
	int sum = 1;
	while (n-- > 0)
		sum *= base;
	return sum;
}
