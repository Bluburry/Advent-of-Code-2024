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

bool remove_start_logic(vector<int> &report)
{

}

bool remove_middle_logic(vector<int> &report)
{

}

int reports_safety_v2(vector<vector<int>> &reports)
{
	int safety_count = 0;
	bool incremental, safe, tolerance;

	for (vector<int> report : reports)
	{

		if (safe)
			safety_count++;
	}

	return safety_count;
}

/* bool safety_check_forward(vector<int> &og_report)
{
	vector<int> report = og_report;

	bool incremental, tolerance = false;

	if (report.at(0) == report.at(1))
	{
		report.erase(report.begin() + 1);
		tolerance = true;
		if (report.at(0) == report.at(1))
			return false;
	}
	if (report.at(0) < report.at(1))
		incremental = true;
	else
		incremental = false;

	for (size_t i = 0; i < report.size() - 1; i++)
	{
		if (incremental &&
			(report.at(i + 1) - report.at(i) <= 0 ||
			 report.at(i + 1) - report.at(i) > 3))
		{
			if (tolerance)
			{
				return false;
			}
			else
			{
				tolerance = true;
				report.erase(report.begin() + i + 1);
			}
		}
		else if (!incremental &&
				 (report.at(i + 1) - report.at(i) >= 0 ||
				  report.at(i + 1) - report.at(i) < -3))
		{
			if (tolerance)
			{
				return false;
			}
			else
			{
				tolerance = true;
				report.erase(report.begin() + i + 1);
			}
		}
	}
	return true;
}

bool safety_check_backward(vector<int> &og_report)
{
	vector<int> report = og_report;

	bool incremental, tolerance = false;

	if (report.at(0) == report.at(1))
	{
		report.erase(report.begin());
		tolerance = true;
		if (report.at(0) == report.at(1))
			return false;
	}
	if (report.at(0) < report.at(1))
		incremental = true;
	else
		incremental = false;

	for (size_t i = report.size() - 1; i > 0; i--)
	{
		if (incremental &&
			(report.at(i) - report.at(i - 1) <= 0 ||
			 report.at(i) - report.at(i - 1) > 3))
		{
			if (tolerance)
			{
				return false;
			}
			else
			{
				tolerance = true;
				report.erase(report.begin() + i - 1);
			}
		}
		else if (!incremental &&
				 (report.at(i) - report.at(i - 1) >= 0 ||
				  report.at(i) - report.at(i - 1) < -3))
		{
			if (tolerance)
			{
				return false;
			}
			else
			{
				tolerance = true;
				report.erase(report.begin() + i - 1);
			}
		}
	}
	return true;
}

int reports_safety_v2(vector<vector<int>> &reports)
{
	int safety_count = 0, i = 0;

	for (vector<int> report : reports)
	{
		if (safety_check_forward(report) || safety_check_backward(report))
		{
			cout << GREEN << i << "\t|\t";
			safety_count++;
		}
		else
			cout << RED << i << "\t|\t";
		i++;
		if (i % 7 == 0)
			cout << endl;
	}

	cout << RESET << endl;

	return safety_count;
} */

/* int reports_safety_v2(vector<vector<int>> &reports)
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

		// check if best to skip i or i + 1
		for (size_t i = 0; i < report.size() - 1; i++)
		{
			if (incremental &&
				(report.at(i + 1) - report.at(i) <= 0 ||
				 report.at(i + 1) - report.at(i) > 3))
			{
				if (tolerance ||
					((i < report.size() - 2 && i > 0 &&
					  (report.at(i + 2) - report.at(i) <= 0 ||
					   report.at(i + 2) - report.at(i) > 3) &&
					  (report.at(i + 1) - report.at(i - 1) <= 0 ||
					   report.at(i + 1) - report.at(i - 1) > 3))))
				{
					safe = false;
					break;
				}
				else
				{
					tolerance = true;
					if (i < report.size() - 2 &&
						report.at(i + 2) - report.at(i) > 0 &&
						report.at(i + 2) - report.at(i) <= 3)
						i += 2;
				}
			}
			else if (!incremental &&
					 (report.at(i + 1) - report.at(i) >= 0 ||
					  report.at(i + 1) - report.at(i) < -3))
			{
				if (tolerance ||
					((i < report.size() - 2 && i > 0 &&
					  (report.at(i + 2) - report.at(i) >= 0 ||
					   report.at(i + 2) - report.at(i) < -3) &&
					  (report.at(i + 1) - report.at(i - 1) >= 0 ||
					   report.at(i + 1) - report.at(i - 1) < -3))))
				{
					safe = false;
					break;
				}
				else
				{
					tolerance = true;
					if (i < report.size() - 2 &&
						report.at(i + 2) - report.at(i) < 0 &&
						report.at(i + 2) - report.at(i) >= -3)
						i += 2;
				}
			}
		}

		if (safe)
			safety_count++;
	}

	return safety_count;
} */
