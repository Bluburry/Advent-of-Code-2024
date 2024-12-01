#include "aoc_day1.hpp"

/**
* @brief This function checks for similar values between the two lists,
	counting the number of times that values appears in the second list,
	then multiplying by that value in the first list.
	The lists need to be sorted for this function to work.
* @param list1 first sorted list
* @param list2 second sorted list
*/
int list_get_similarity(vector<int> &list1, vector<int> &list2)
{
	double ret = 0;

	for (size_t i = 0, j = 1, k = 0; k < list1.size() && i < list2.size(); j = 1)
	{
		/* cout << list1.at(k) << " | " << list2.at(i) << endl; */
		if (list1.at(k) == list2.at(i))
		{
			// counts how many times the same number appears consequently
			for (; list2.at(i) == list2.at(i + j); j++)
			{
			}
			ret += list1.at(k) * j;
			// increments i, j times, so that the right list skips the the similar values
			i += j;
			/* cout << list1.at(k) << " * " << j << endl; */
		}
		// if not the same, increments the left list if the value is smaller than the right list
		else if (list1.at(k) < list2.at(i))
			k++;
		// does the same, except for the right list
		else if (list1.at(k) > list2.at(i))
			i++;
		else
			cout << "i probably dun goofed" << endl;

		// list2_repeats_map[list2.at(i)] = j;
	}

	/* for (auto it = list2_repeats_map.cbegin(); it != list2_repeats_map.cend(); it++)
		cout << "map: " << it->first << ", " << it->second << endl; */

	return ret;
}
