#include "aoc_day6.hpp"

static void guard_start(char **map, int size_i, int size_j, int &pos_i, int &pos_j)
{
	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			if (map[i][j] != '#' && map[i][j] != '.')
			{
				pos_i = i;
				pos_j = j;
				return;
			}
		}
	}
}

int guard_movement(char **map, int size_i, int size_j)
{
	char direction;
	int pos_i, pos_j;

	guard_start(map, size_i, size_j, pos_i, pos_j);

	switch (map[pos_i][pos_j])
	{
	case '^':
		direction = 'u';
		break;
	case '>':
		direction = 'r';
		break;
	case '<':
		direction = 'l';
		break;
	case 'v':
		direction = 'l';
		break;
	default:
		direction = 'd';
		break;
	}

	bool left = false;
	int movement_count = 0;
	map[pos_i][pos_j] = 'X';

	while (pos_i >= 0 && pos_i < size_i && pos_j >= 0 && pos_j < size_j && !left)
	{
		switch (direction)
		{
		case 'u':
			if (pos_i > 0 && map[pos_i - 1][pos_j] == '#')
				direction = 'r';
			else if (pos_i > 0)
			{
				pos_i--;
				movement_count++;
			}
			else // if (pos_i == 0)
			{
				left = true;
				movement_count++;
			}
			map[pos_i][pos_j] = 'X';
			break;
		case 'l':
			if (pos_j > 0 && map[pos_i][pos_j - 1] == '#')
				direction = 'u';
			else if (pos_j > 0)
			{
				pos_j--;
				movement_count++;
			}
			else // if (pos_j == 0)
			{
				left = true;
				movement_count++;
			}
			map[pos_i][pos_j] = 'X';
			break;
		case 'r':
			if (pos_j < size_j - 1 && map[pos_i][pos_j + 1] == '#')
				direction = 'd';
			else if (pos_j < size_j - 1)
			{
				pos_j++;
				movement_count++;
			}
			else // if (pos_j == size_j)
			{
				left = true;
				movement_count++;
			}
			map[pos_i][pos_j] = 'X';
			break;
		case 'd':
			if (pos_i < size_i - 1 && map[pos_i + 1][pos_j] == '#')
				direction = 'l';
			else if (pos_i < size_i - 1)
			{
				pos_i++;
				movement_count++;
			}
			else // if (pos_i == size_i)
			{
				left = true;
				movement_count++;
			}
			map[pos_i][pos_j] = 'X';
			break;
		default:
			map[pos_i][pos_j] = '?';
			cout << "wtf" << endl;
			break;
		}
	}

	return movement_count;
}