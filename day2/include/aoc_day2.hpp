#ifndef _AOC_DAY2_HPP
#define _AOC_DAY2_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

#define RESET "\033[0m"
#define RED "\033[0;31m"	 // Correct
#define GREEN "\033[0;32m"	 // Incorrect
#define YELLOW "\033[0;33m"	 // ClapTrap
#define BLUE "\033[0;34m"	 // ScavTrap
#define MAGENTA "\033[0;35m" // FragTrap
#define CYAN "\033[0;36m"	 // DiamondTrap

using namespace std;

vector<vector<int>> reports_parse(char *fl);
int reports_safety_v1(vector<vector<int>> &reports);
int reports_safety_v2(vector<vector<int>> &reports);

#endif 
