#include "aoc_day4.hpp"

char xmas_array[] = "XMAS";

/*
	1 - ←
	2 - ↖
	3 - ↑
	4 - ↗
	5 - →
	6 - ↘
	7 - ↓
	8 - ↙
*/
// possibly need to check if i/j don't pass size limit when only one of them moves
bool recursive_search(vector<string> &words, int i, int j, int searching, char direction)
{
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