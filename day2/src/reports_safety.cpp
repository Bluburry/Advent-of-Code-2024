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

bool middle_logic(vector<int> &report, bool incremental)
{
	bool tolerance = false;

	for (int i = 0; i < (int)report.size() - 1; i++)
	{
		if (abs(report.at(i + 1) - report.at(i)) == 0 ||
			abs(report.at(i + 1) - report.at(i)) > 3)
		{
			if (tolerance)
				return false;
			tolerance = true;
			if (report.at(i + 1) == report.at(i) ||
				abs(report.at(i + 1) - report.at(i)) > 3 ||
				(incremental && report.at(i + 1) < report.at(i)) ||
				(!incremental && report.at(i + 1) > report.at(i)))
			{
				report.erase(report.begin() + i + 1);
				i--;
			}
		}
	}
	return true;
}

int reports_safety_v2(vector<vector<int>> &reports)
{
	int safety_count = 0;
	bool incremental;

	for (vector<int> report : reports)
	{
		if (report.at(report.size() - 1) > report.at(0))
			incremental = true;
		else if (report.at(report.size() - 1) < report.at(0))
			incremental = false;
		else
		{
			incremental = true;
			int diff = 0;
			for (int i = 0; i < (int)report.size() - 1; i++)
				diff = report.at(i + 1) - report.at(i);
			if (diff < 0)
				incremental = false;
			else if (diff == 0)
				continue;
		}

		if (middle_logic(report, incremental))
			safety_count++;
	}

	return safety_count;
}
