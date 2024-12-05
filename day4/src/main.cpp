#include "aoc_day4.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	vector<string> xmas = words_parse(argv[1]);

	cout << xmas_search(xmas) << endl;

	return 0;
}