#include "aoc_day4.hpp"

vector<string> words_parse(char *fl)
{
	vector<string> ret;
	string line;

	ifstream reports_file(fl);

	if (!reports_file.is_open())
	{
		cerr << "Error opening file\n";
		exit(EXIT_FAILURE);
	}

	while (getline(reports_file, line))
		ret.push_back(line);

	reports_file.close();

	return ret;
}
