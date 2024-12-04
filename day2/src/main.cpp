#include "aoc_day2.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	// cout << argv[1] << endl;

	vector<vector<int>> reports = reports_parse(argv[1]);

	// cout << reports.size() << endl;
	/* for (vector<int> report : reports)
	{
		for (int level : report)
			cout << level << " | ";
		cout << endl;
	} */

	cout << "Safety level 1 (puzzle 1): " << reports_safety_v1(reports) << endl;
	cout << "Safety level 2 (puzzle 2): " << reports_safety_v2(reports) << RED << " NOT CORRECT " << RESET << endl;
	// cout << reports_safety_v2(reports) << endl;

	return 0;
}