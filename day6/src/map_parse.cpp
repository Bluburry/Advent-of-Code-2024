#include "aoc_day6.hpp"

vector<string> map_helper(char *fl)
{
	vector<string> helper;
	string line;

	ifstream map_file(fl);

	if (!map_file.is_open())
	{
		cerr << "Error opening file\n";
		exit(EXIT_FAILURE);
	}

	while (getline(map_file, line))
		helper.push_back(line);

	map_file.close();

	return helper;
}

char **map_parse(vector<string> &helper)
{
	char **ret;

	ret = new char *[helper.size()];

	for (int i = 0; i < (int)helper.size(); i++)
	{
		ret[i] = new char [helper.at(i).size()];
		for (int j = 0; j < (int)helper.at(i).size(); j++)
		{
			ret[i][j] = helper.at(i).at(j);
		}
	}

	return ret;
}
