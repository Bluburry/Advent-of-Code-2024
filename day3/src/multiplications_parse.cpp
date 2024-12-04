#include "aoc_day3.hpp"

vector<string> multiplications_parse(char *fl)
{
	regex r("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
	vector<string> helper, ret;
	smatch placeholder;
	string line;

	ifstream reports_file(fl);

	if (!reports_file.is_open())
	{
		cerr << "Error opening file\n";
		exit(EXIT_FAILURE);
	}

	while (getline(reports_file, line))
		helper.push_back(line);

	reports_file.close();

	for (string line : helper)
	{

		while (regex_search(line, placeholder, r))
		{
			ret.push_back(placeholder.str());
			line = placeholder.suffix().str();
		}
	}

	return ret;
}

vector<string> multiplications_parse_v2(char *fl)
{
	regex r("mul\\([0-9]{1,3},[0-9]{1,3}\\)|do\\(\\)|don't\\(\\)");
	vector<string> helper, ret;
	smatch placeholder;
	string line;

	ifstream reports_file(fl);

	if (!reports_file.is_open())
	{
		cerr << "Error opening file\n";
		exit(EXIT_FAILURE);
	}

	while (getline(reports_file, line))
		helper.push_back(line);

	reports_file.close();

	for (string line : helper)
	{
		while (regex_search(line, placeholder, r))
		{
			ret.push_back(placeholder.str());
			line = placeholder.suffix().str();
		}
	}

	return ret;
}
