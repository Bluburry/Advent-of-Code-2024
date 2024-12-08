#include "aoc_day5.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	vector<vector<int>> rules, pages, rules_v2;

	vector<string> lines = pages_parse(argv[1]);

	update_parse_v2(lines, rules, pages, rules_v2);

	cout << rules_check(rules_v2, pages) << endl;
	cout << rules_check_v2(rules_v2, pages) << endl;

	return 0;
}