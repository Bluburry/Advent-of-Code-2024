#include "aoc_day4.hpp"

char xmas_array[] = "XMAS";

/**
 * @brief recursively searching in the defined direction,
 * checking a char array that contains "XMAS"
 * @param words vector of strings that contain the words to find
 * @param i index i
 * @param j index j
 * @param searching index of "XMAS" array currently searching for
 * @param direction char from 1 to 8 dictating the search direction:
	1 - ←
	2 - ↖
	3 - ↑
	4 - ↗
	5 - →
	6 - ↘
	7 - ↓
	8 - ↙
 */
static bool recursive_search(vector<string> &words, int i, int j, int searching, char direction)
{
	// possibly need to check if i/j don't pass size limit when only one of them moves
	// (not needed with given input)
	if (searching >= 4)
		return true;
	else if (i < 0 || i >= (int)words.size() || j < 0 || j > (int)words.at(i).size())
		return false;

	switch (direction)
	{
	case 1: // ←
		if (j > 0 && words.at(i).at(j - 1) == xmas_array[searching])
			return recursive_search(words, i, j - 1, searching + 1, direction);
		break;
	case 2: // ↖
		if (i > 0 && j > 0 && words.at(i - 1).at(j - 1) == xmas_array[searching])
			return recursive_search(words, i - 1, j - 1, searching + 1, direction);
		break;
	case 3: // ↑
		if (i > 0 && words.at(i - 1).at(j) == xmas_array[searching])
			return recursive_search(words, i - 1, j, searching + 1, direction);
		break;
	case 4: // ↗
		if (i > 0 && j < (int)words.at(i - 1).size() - 1 && words.at(i - 1).at(j + 1) == xmas_array[searching])
			return recursive_search(words, i - 1, j + 1, searching + 1, direction);
		break;
	case 5: // →
		if (j < (int)words.at(i).size() - 1 && words.at(i).at(j + 1) == xmas_array[searching])
			return recursive_search(words, i, j + 1, searching + 1, direction);
		break;
	case 6: // ↘
		if (i < (int)words.size() - 1 && j < (int)words.at(i + 1).size() - 1 && words.at(i + 1).at(j + 1) == xmas_array[searching])
			return recursive_search(words, i + 1, j + 1, searching + 1, direction);
		break;
	case 7: // ↓
		if (i < (int)words.size() - 1 && words.at(i + 1).at(j) == xmas_array[searching])
			return recursive_search(words, i + 1, j, searching + 1, direction);
		break;
	case 8: // ↙
		if (i < (int)words.size() - 1 && j > 0 && words.at(i + 1).at(j - 1) == xmas_array[searching])
			return recursive_search(words, i + 1, j - 1, searching + 1, direction);
		break;
	default:
		break;
	}

	return false;
}

int xmas_search(vector<string> &words)
{
	int ret = 0;

	for (int i = 0; i < (int)words.size(); i++)
	{
		for (int j = 0; j < (int)words.at(i).size(); j++)
		{
			if (words.at(i).at(j) == 'X')
			{
				for (int k = 1; k <= 8; k++)
				{
					if (recursive_search(words, i, j, 1, k))
						ret++;
				}
			}
		}
	}

	return ret;
}

static bool x_mas_logic(vector<string> &xmas, int i, int j)
{
	bool found_m = false, found_s = false, approved = false;

	if (xmas.at(i - 1).at(j - 1) == 'M')
		found_m = true;
	else if (xmas.at(i - 1).at(j - 1) == 'S')
		found_s = true;

	if (found_s && (xmas.at(i + 1).at(j + 1) == 'M'))
		approved = true;
	else if (found_m && (xmas.at(i + 1).at(j + 1) == 'S'))
		approved = true;

	if (!approved)
		return false;

	approved = false;
	found_m = false;
	found_s = false;

	if (xmas.at(i - 1).at(j + 1) == 'M')
		found_m = true;
	else if (xmas.at(i - 1).at(j + 1) == 'S')
		found_s = true;

	if (found_s && (xmas.at(i + 1).at(j - 1) == 'M'))
		approved = true;
	else if (found_m && (xmas.at(i + 1).at(j - 1) == 'S'))
		approved = true;

	return approved;
}

int xmas_search_v2(vector<string> &words)
{
	int ret = 0;

	for (int i = 1; i < (int)words.size() - 1; i++)
	{
		for (int j = 1; j < (int)words.at(i).size() - 1; j++)
		{
			if (words.at(i).at(j) == 'A')
			{
				if (x_mas_logic(words, i, j))
					ret++;
			}
		}
	}

	return ret;
}