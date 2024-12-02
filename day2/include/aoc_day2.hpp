#ifndef _AOC_DAY2_HPP
#define _AOC_DAY2_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> reports_parse(char *fl);
int reports_safety_v1(vector<vector<int>> &reports);
int reports_safety_v2(vector<vector<int>> &reports);

#endif 
