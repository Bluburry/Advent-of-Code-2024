#include "aoc_day6.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	vector<string> helper = map_helper(argv[1]);
	char **map = map_parse(helper);
	char **map_backup = map_parse(helper);
	int size_i = (int)helper.size(), size_j = (int)helper.at(0).size();

	cout << "Advent day 6 (puzzle 1): " << GREEN << guard_movement(map, size_i, size_j) << RESET << endl;
	cout << "Advent day 6 (puzzle 2): " << guard_loop(map_backup, map, size_i, size_j) << endl;

	for (int i = 0; i < size_i; i++)
		delete[] map[i];
	for (int i = 0; i < size_i; i++)
		delete[] map_backup[i];

	delete[] map;
	delete[] map_backup;

	return 0;
}