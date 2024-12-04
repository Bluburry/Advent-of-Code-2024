#include "aoc_day3.hpp"

double memory_mult(vector<string> &memory)
{
	double ret = 0;
	int helper1, helper2, i;

	for (string mul : memory)
	{
		i = 0;
		for (; i < (int)mul.size() && mul.at(i) != ','; i++)
		{
		}
		helper1 = atoi(mul.substr(4, i).c_str());
		helper2 = atoi(mul.substr(i + 1, mul.size()).c_str());

		ret += helper1 * helper2;
	}

	return ret;
}

double memory_mult_v2(vector<string> &memory)
{
	double ret = 0;
	int helper1, helper2, i;
	bool do_mult = true;

	for (string mul : memory)
	{
		if (mul == "do()")
		{
			do_mult = true;
			continue;
		}
		else if (mul == "don't()")
		{
			do_mult = false;
			continue;
		}
		if (!do_mult)
			continue;
		i = 0;
		for (; i < (int)mul.size() && mul.at(i) != ','; i++)
		{
		}
		helper1 = atoi(mul.substr(4, i).c_str());
		helper2 = atoi(mul.substr(i + 1, mul.size()).c_str());

		ret += helper1 * helper2;
	}

	return ret;
}
