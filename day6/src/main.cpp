#include "aoc_day6.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	vector<string> helper = map_helper(argv[1]);
	char **map = map_parse(helper);

	

	for (int i = 0; i < (int)helper.size(); i++)
		delete[] map[i];

	delete[] map;

	return 0;
}