#include "aoc_day4.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	vector<string> xmas = words_parse(argv[1]);

	cout << GREEN << "Day 4 (puzzle 1): " << xmas_search(xmas) << endl;

	cout << "Day 4 (puzzle 2): " << xmas_search_v2(xmas) << RESET << endl;

	return 0;
}