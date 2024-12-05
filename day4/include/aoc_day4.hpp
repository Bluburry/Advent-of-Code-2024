#ifndef _AOC_DAY4_HPP
#define _AOC_DAY4_HPP

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

vector<string> words_parse(char *fl);
int xmas_search(vector<string> &words);
int xmas_search_v2(vector<string> &words);

#endif 
