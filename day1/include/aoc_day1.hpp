#ifndef _AOC_DAY_HPP
#define _AOC_DAY_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool list_parse(vector<int> &list1, vector<int> &list2, char *fl);
int list_get_difference(vector<int> &list1, vector<int> &list2);
int list_get_similarity(vector<int> &list1, vector<int> &list2);

#endif 
