#include "aoc_day2.hpp"

vector<int> report_level_parse(string line)
{
	const char *line_helper = line.c_str();
	vector<int> report_line;
	int i = 0, j = 0;

	while (line_helper[j])
	{
		i = j;
		while (line_helper[j] && line_helper[j] >= 48 && line_helper[j] <= 57)
			j++;

		report_line.push_back(atoi(line.substr(i, j).c_str()));

		while (line_helper[j] && !(line_helper[j] >= 48 && line_helper[j] <= 57))
			j++;
	}

	return report_line;
}

vector<vector<int>> reports_parse(char *fl)
{
	vector<vector<int>> reports;
	string line;

	ifstream reports_file(fl);

	if (!reports_file.is_open())
	{
		cerr << "Error opening file\n";
		exit(EXIT_FAILURE);
	}

	while (getline(reports_file, line))
	{
		// cout << line << endl;
		reports.push_back(report_level_parse(line));
	}

	reports_file.close();
	return reports;
}
