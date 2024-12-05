#include "aoc_day5.hpp"

vector<string> pages_parse(char *fl)
{
	vector<string> ret;
	string line;

	ifstream pages_file(fl);

	if (!pages_file.is_open())
	{
		cerr << "Error opening file\n";
		exit(EXIT_FAILURE);
	}

	while (getline(pages_file, line))
		ret.push_back(line);

	pages_file.close();

	return ret;
}

void update_parse(vector<string> &manual, vector<vector<int>> &rules, vector<vector<int>> &pages)
{
	int i = 0;
	string aux_str;

	for (int j; i < (int)manual.size() && manual.at(i).find('|') != string::npos; i++)
	{
		aux_str = manual.at(i);
		j = aux_str.find('|');
		rules.push_back({atoi(aux_str.substr(0, j).c_str()), atoi(aux_str.substr(j + 1, aux_str.size()).c_str())});
	}

	i++;

	for (; i < (int)manual.size(); i++)
	{
		aux_str = manual.at(i);
		vector<int> aux_vec;
		string helper;
		stringstream ss(aux_str);
		while (getline(ss, helper, ','))
			aux_vec.push_back(atoi(helper.c_str()));
		pages.push_back(aux_vec);
	}

	sort(rules.begin(), rules.end(), [](const vector<int> &a, const vector<int> &b) {
		if (a.at(1) == b.at(1))
			return a.at(0) < b.at(0);
		return a.at(1) < b.at(1);
	});
}
