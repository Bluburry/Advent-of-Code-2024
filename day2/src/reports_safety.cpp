#include "aoc_day2.hpp"

int reports_safety(vector<vector<int>> &reports)
{
	int safety_count = 0;
	bool incremental, safe;

	cout << boolalpha;

	cout << reports.size() << endl;

	for (vector<int> report : reports)
	{
		safe = true;

		if (report.at(0) == report.at(1))
			break;
		else if (report.at(0) < report.at(1))
			incremental = true;
		else
			incremental = false;

		for (int i : report) {
			cout << i << " | ";
		}

		cout << "incremental: " << incremental << ", ";

		for (size_t i = 1; i < report.size(); i++)
		{
			cout << report.at(i) - report.at(i - 1) << " | ";
			if (incremental && (report.at(i) - report.at(i - 1) <= 0 || report.at(i) - report.at(i - 1) > 3))
			{
				safe = false;
				break;
			}
			else if (!incremental && (report.at(i) - report.at(i - 1) >= 0 || report.at(i) - report.at(i - 1) < -3))
			{
				safe = false;
				break;
			}
		}

		cout << "safe: " << safe << endl;

		if (safe)
		{
			/* cout << "safe, incremental: " << incremental << ", line:\t";
			for (int level : report)
				cout << level << " | ";
			cout << endl; */
			safety_count++;
		}
	}

	return safety_count;
}
