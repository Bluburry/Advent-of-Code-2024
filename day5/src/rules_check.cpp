#include "aoc_day5.hpp"

static int custom_rules_find(vector<vector<int>> &rules_v2, int search_value, int index_start, int index_end)
{
	if (index_start < 0 || index_end >= (int)rules_v2.size() || index_end <= index_start)
		return -1;

	if (search_value == rules_v2.at(index_start).at(0))
		return index_start;
	else if (search_value == rules_v2.at(index_end).at(0))
		return index_end;

	if (index_end - index_start <= 1)
		return -1;

	int i = (index_end - index_start) / 2 + index_start;

	if (search_value == rules_v2.at(i).at(0))
	{
		/* while (i > 0 && rules_v2.at(i).at(0) == rules_v2.at(i - 1).at(0))
			i--; */
		return i;
	}
	else if (search_value > rules_v2.at(i).at(0))
	{
		/* if (i < index_end - 1 && rules_v2.at(i).at(0) != rules_v2.at(i + 1).at(0))
			return custom_rules_find(rules_v2, search_value, i + 1, index_end);
		// skip repeat values
		while (i < index_end - 1 && rules_v2.at(i).at(0) == rules_v2.at(i + 1).at(0))
			i++; */
		return custom_rules_find(rules_v2, search_value, i + 1, index_end);
	}
	else if (search_value < rules_v2.at(i).at(0))
	{
		/* if (i > 0 && rules_v2.at(i).at(0) != rules_v2.at(i - 1).at(0))
			return custom_rules_find(rules_v2, search_value, index_start, i - 1);
		// skip repeat values
		while (i > 0 && rules_v2.at(i).at(0) == rules_v2.at(i - 1).at(0))
			i--; */
		return custom_rules_find(rules_v2, search_value, index_start, i - 1);
	}

	return -1;
}

static bool follows_rules_check(vector<vector<int>> &rules_v2, vector<int> &pages, int pages_index, int rules_index)
{
	bool found = false;
	vector<int> rules_found;

	for (int i = 1; i < (int)rules_v2.at(rules_index).size(); i++)
	{
		for (int j = 0; j < (int)pages.size(); j++)
		{
			if (j == pages_index)
				continue;
			if (pages.at(j) == rules_v2.at(rules_index).at(i))
			{
				found = true;
				rules_found.push_back(rules_v2.at(rules_index).at(i));
			}
		}
	}

	if (!found)
		return true;

	for (int i = 0; i < (int)rules_found.size(); i++)
	{
		found = false;
		for (int j = 0; j < pages_index && !found; j++)
		{
			if (rules_found.at(i) == pages.at(j))
				found = true;
		}
		if (!found)
			return false;
	}

	return true;
}

int rules_check(vector<vector<int>> &rules, vector<vector<int>> &update_pages)
{
	bool valid;
	int ret = 0, aux;

	for (vector<int> pages : update_pages)
	{
		valid = true;

		for (int i = 0, index; i < (int)pages.size(); i++)
		{
			index = custom_rules_find(rules, pages[i], 0, (int)rules.size() - 1);
			if (index != -1)
			{
				if (!follows_rules_check(rules, pages, i, index))
				{
					valid = false;
					break;
				}
			}
		}

		if (valid)
		{
			aux = (int)pages.size() / 2;
			if ((int)pages.size() % 2 == 0)
				aux++;
			ret += pages.at(aux);
		}
	}

	return ret;
}

static void fix_page_order(vector<vector<int>> &rules_v2, vector<int> &pages)
{
	bool found;

	for (int i = 0; i < (int)pages.size(); i++, found = false)
	{
		found = false;
		vector<int> aux;
		for (vector<int> rules : rules_v2)
		{
			if (pages.at(i) == rules.at(0))
			{
				for (int j = 0; j < (int)pages.size(); j++)
				{
					if (j == i)
						continue;
					for (int k = 1; k < (int)rules.size(); k++)
					{
						if (pages.at(j) == rules.at(k))
						{
							if (!found)
								found = true;
							aux.push_back(rules.at(k));
						}
					}
				}
			}
			if (found)
				break;
		}

		if (!found)
			continue;

		found = false;

		// h = i;
		for (int rule : aux)
		{
			for (int j = i + 1; j < (int)pages.size(); j++)
			{
				if (pages.at(j) == rule)
				{
					pages.at(j) = pages.at(i);
					pages.at(i) = rule;
					found = true;
					i = j;
					break;
				}
			}
		}

		if (found)
			i = -1;
	}
} 

int rules_check_v2(vector<vector<int>> &rules_v2, vector<vector<int>> &update_pages)
{
	bool valid;
	int ret = 0, aux;

	for (vector<int> pages : update_pages)
	{
		valid = true;

		for (int i = 0, index; i < (int)pages.size(); i++)
		{
			index = custom_rules_find(rules_v2, pages.at(i), 0, (int)rules_v2.size() - 1);
			if (index != -1)
			{
				if (!follows_rules_check(rules_v2, pages, i, index))
				{
					valid = false;
					fix_page_order(rules_v2, pages);
					break;
				}
			}
		}

		if (!valid)
		{
			aux = (int)pages.size() / 2;
			if ((int)pages.size() % 2 == 0)
				aux++;
			ret += pages[aux];
		}
	}

	return ret;
}

// wanted to try building a O(log n) search algorithm,
// especially as vector find has O(n) complexity
/* static int custom_rules_find(vector<vector<int>> &rules, int search_value, int index_start, int index_end)
{
	if (index_start < 0 || index_end >= (int)rules.size() || index_end <= index_start)
		return -1;

	if (search_value == rules.at(index_start).at(1))
		return index_start;
	else if (search_value == rules.at(index_end).at(1))
		return index_end;

	if (index_end - index_start  <= 1)
		return -1;

	int i = (index_end - index_start) / 2 + index_start;

	if (search_value == rules.at(i).at(1))
	{
		while (i > 0 && rules.at(i).at(1) == rules.at(i - 1).at(1))
			i--;
		return i;
	}
	else if (search_value > rules.at(i).at(1))
	{
		if (i < index_end - 1 && rules.at(i).at(1) != rules.at(i + 1).at(1))
			return custom_rules_find(rules, search_value, i + 1, index_end);
		// skip repeat values
		while (i < index_end - 1 && rules.at(i).at(1) == rules.at(i + 1).at(1))
			i++;
		return custom_rules_find(rules, search_value, i, index_end);
	}
	else if (search_value < rules.at(i).at(1))
	{
		if (i > 0 && rules.at(i).at(1) != rules.at(i - 1).at(1))
			return custom_rules_find(rules, search_value, index_start, i - 1);
		// skip repeat values
		while (i > 0 && rules.at(i).at(1) == rules.at(i - 1).at(1))
			i--;
		return custom_rules_find(rules, search_value, index_start, i);
	}

	return -1;
}

static bool follows_rules_check(vector<vector<int>> &rules, vector<int> &pages, int pages_index, int rules_index)
{
	bool found = false;
	vector<int> rules_found;

	for (int i = rules_index; i < (int)rules.size() && rules.at(i).at(1) == pages[pages_index]; i++)
	{
		for (int j = 0; j < (int)pages.size(); j++)
		{
			if (j == pages_index)
				continue;
			if (pages[j] == rules[i][0])
			{
				found = true;
				rules_found.push_back(rules[i][0]);
			}
		}
	}

	if (!found)
		return true;

	for (int i = 0; i < (int) rules_found.size(); i++)
	{
		found = false;
		for (int j = 0; j < pages_index && !found; j++)
		{
			if (rules_found[i] == pages[j])
				found = true;
		}
		if (!found)
			return false;
	}

	return true;
} */
