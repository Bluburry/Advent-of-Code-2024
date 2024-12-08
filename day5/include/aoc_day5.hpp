#ifndef _AOC_DAY5_HPP
#define _AOC_DAY5_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"

using namespace std;

vector<string> pages_parse(char *fl);
void update_parse(vector<string> &manual, vector<vector<int>> &rules, vector<vector<int>> &pages);
void update_parse_v2(vector<string> &manual, vector<vector<int>> &rules, vector<vector<int>> &pages, vector<vector<int>> &rules_v2);
int rules_check(vector<vector<int>> &rules, vector<vector<int>> &update_pages);
int rules_check_v2(vector<vector<int>> &rules_v2, vector<vector<int>> &update_pages);

#endif 
