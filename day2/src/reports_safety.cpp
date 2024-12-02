#include "aoc_day2.hpp"

int reports_safety_v1(vector<vector<int>> &reports)
{
	int safety_count = 0;
	bool incremental, safe;

	for (vector<int> report : reports)
	{
		safe = true;

		if (report.at(0) == report.at(1))
			continue;
		else if (report.at(0) < report.at(1))
			incremental = true;
		else
			incremental = false;

		for (size_t i = 1; i < report.size(); i++)
		{
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

		if (safe)
			safety_count++;
	}

	return safety_count;
}

int reports_safety_v2(vector<vector<int>> &reports)
{
	int safety_count = 0;
	bool incremental, safe, tolerance;

	for (vector<int> report : reports)
	{
		tolerance = false;
		safe = true;

		if (report.at(0) == report.at(1))
			continue;
		else if (report.at(0) < report.at(1))
			incremental = true;
		else
			incremental = false;

		for (size_t i = 0; i < report.size() - 1; i++)
		{
			if (incremental &&
				(report.at(i + 1) - report.at(i) <= 0 ||
				 report.at(i + 1) - report.at(i) > 3))
			{
				if (tolerance ||
					(i < report.size() - 2 &&
					 (report.at(i + 2) - report.at(i) <= 0 ||
					  report.at(i + 2) - report.at(i) > 3)))
				{
					safe = false;
					break;
				}
				else
				{
					tolerance = true;
					i++;
				}
			}
			else if (!incremental &&
					 (report.at(i + 1) - report.at(i) >= 0 ||
					  report.at(i + 1) - report.at(i) < -3))
			{
				if (tolerance ||
					(i < report.size() - 2 &&
					 (report.at(i + 2) - report.at(i) >= 0 ||
					  report.at(i + 2) - report.at(i) < -3)))
				{
					safe = false;
					break;
				}
				else
				{
					tolerance = true;
					i++;
				}
			}
		}

		if (safe)
			safety_count++;
		else
		{
			cout << "\nunsafe: ";
			for (int i : report)
				cout << i << " ";
		}
	}

	return safety_count;
}
