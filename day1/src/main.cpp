#include "aoc_day1.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	cout << argv[1] << endl;

	vector<int> list1, list2;

	list_parse(list1, list2, argv[1]);

	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());


	/* cout << "printing lists:\n";

	for (size_t i = 0; i < list1.size(); i++) {
		cout << list1.at(i) << " | " << list2.at(i) << endl;
	} */

	cout << "Difference (puzzle 1): " << list_get_difference(list1, list2) << endl;

	cout << "Similarity (puzzle 2): " << list_get_similarity(list1, list2) << endl;

	return 0;
}