#include "aoc_day5.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	vector<vector<int>> rules, pages;

	vector<string> lines = pages_parse(argv[1]);

	update_parse(lines, rules, pages);

	cout << rules_check(rules, pages) << endl;
	cout << rules_check_v2(rules, pages) << endl;

	return 0;
}