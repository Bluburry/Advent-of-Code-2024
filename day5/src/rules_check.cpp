#include "aoc_day5.hpp"

// wanted to try building a O(log n) search algorithm,
// especially as vector find has O(n) complexity
static int custom_rules_find(vector<vector<int>> &rules, int search_value, int index_start, int index_end)
{
	if (index_start < 0 || index_end >= (int)rules.size() || index_end <= index_start)
		return -1;

	if (search_value == rules[index_start][1])
		return index_start;
	else if (search_value == rules[index_end][1])
		return index_end;
	
	if (index_end - index_start  <= 1)
		return -1;

	int i = (index_end - index_start) / 2 + index_start;

	if (search_value == rules[i][1])
	{
		while (i > 0 && rules[i][1] == rules[i - 1][1])
			i--;
		return i;
	}
	else if (search_value > rules[i][1])
	{
		if (i < index_end - 1 && rules[i][1] != rules[i + 1][1])
			return custom_rules_find(rules, search_value, i + 1, index_end);
		// skip repeat values
		while (i < index_end - 1 && rules[i][1] == rules[i + 1][1])
			i++;
		return custom_rules_find(rules, search_value, i, index_end);
	}
	else if (search_value < rules[i][1])
	{
		if (i > 0 && rules[i][1] != rules[i - 1][1])
			return custom_rules_find(rules, search_value, index_start, i - 1);
		// skip repeat values
		while (i > 0 && rules[i][1] == rules[i - 1][1])
			i--;
		return custom_rules_find(rules, search_value, index_start, i);
	}

	return -1;
}

static bool follows_rules_check(vector<vector<int>> &rules, vector<int> &pages, int pages_index, int rules_index)
{
	bool found = false;
	vector<int> rules_found;

	for (int i = rules_index; i < (int)rules.size() && rules[i][1] == pages[pages_index]; i++)
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
			ret += pages[aux];
		}
	}

	return ret;
}

static void fix_page_order(vector<vector<int>> &rules, vector<int> pages)
{
	vector<int> placeholder;
	int aux;


}

int rules_check_v2(vector<vector<int>> &rules, vector<vector<int>> &update_pages)
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
					fix_page_order(rules, pages);
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