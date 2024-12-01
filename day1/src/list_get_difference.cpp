#include "aoc_day1.hpp"

int list_get_difference(vector<int> &list1, vector<int> &list2)
{
	int ret = 0;
	for (size_t i = 0; i < list1.size(); i++)
		ret += abs(list1.at(i) - list2.at(i));

	return ret;
}
