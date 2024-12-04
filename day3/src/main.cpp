#include "aoc_day3.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	vector<string> multiplications = multiplications_parse(argv[1]);

	cout << "Advent of code day 3 (puzzle 1): " << fixed << memory_mult(multiplications) << endl;

	multiplications.clear();

	multiplications = multiplications_parse_v2(argv[1]);

	cout << "Advent of code day 3 (puzzle 2): " << fixed << memory_mult_v2(multiplications) << endl;

	return 0;
}