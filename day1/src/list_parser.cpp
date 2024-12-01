#include "aoc_day1.hpp"

string get_delim(char *fl)
{
	string line, delimiter;

	ifstream lists(fl);

	if (!lists.is_open())
	{
		cerr << "Error opening file\n";
		return "";
	}

	if (!getline(lists, line))
	{
		cerr << "Error reading line\n";
		lists.close();
		return "";
	}

	const char *check = line.c_str();
	int i = 0, j;

	while (check[i] >= 48 && check[i] <= 57)
		i++;

	j = i;

	while (!(check[j] >= 48 && check[j] <= 57))
		j++;

	delimiter = line.substr(i, j - i);

	/* cout << line << endl;
	cout << i << endl;
	cout << j << endl;
	std::cout << "delimiter: \"" << delimiter << "\"" << endl; */

	lists.close();

	return delimiter;
}

bool list_parse(vector<int> &list1, vector<int> &list2, char *fl)
{
	string line, l1, l2, delimiter = get_delim(fl);

	if (delimiter.size() == 0)
		return false;

	ifstream lists(fl);

	if (!lists.is_open())
	{
		cerr << "Error opening file\n";
		return false;
	}

	while (getline(lists, line))
	{
		/* std::cout << line.substr(0, line.find(delimiter)) << delimiter;
		std::cout << line.substr(line.find(delimiter), line.size()) << endl; */
		list1.push_back(atoi(line.substr(0, line.find(delimiter)).c_str()));
		list2.push_back(atoi(line.substr(line.find(delimiter), line.size()).c_str()));
	}

	lists.close();
	return true;
}
