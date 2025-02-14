#ifndef _AOC_DAY6_HPP
#define _AOC_DAY6_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>
#include <unistd.h>

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define GUARD_LOOP_MAX 10000

using namespace std;

vector<string> map_helper(char *fl);
char **map_parse(vector<string> &helper);
int guard_movement(char **map, int size_i, int size_j);
int guard_loop(char **map_og, char **map_alt, int size_i, int size_j);

#endif 
