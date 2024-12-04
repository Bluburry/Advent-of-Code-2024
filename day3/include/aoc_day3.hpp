#ifndef _AOC_DAY3_HPP
#define _AOC_DAY3_HPP

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

vector<string> multiplications_parse(char *fl);
vector<string> multiplications_parse_v2(char *fl);
double memory_mult(vector<string> &memory);
double memory_mult_v2(vector<string> &memory);

#endif 
