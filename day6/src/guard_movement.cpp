#include "aoc_day6.hpp"

static char guard_start(char **map, int size_i, int size_j, int &pos_i, int &pos_j)
{
	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			if (map[i][j] != '#' && map[i][j] != '.')
			{
				pos_i = i;
				pos_j = j;
				return map[i][j];
				/* switch (map[pos_i][pos_j])
				{
				case '^':
					return 'u';
				case '>':
					return 'r';
				case '<':
					return 'l';
				case 'v':
					return 'd';
				default:
					return 'u';
				} */
			}
		}
	}
	return '^';
}

/* static void draw_map(char **map, int size_i, int size_j, int cnt)
{
	system("clear");

	cout << "Movement count: " << cnt << endl;
	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
} */

int guard_movement(char **map, int size_i, int size_j)
{
	char direction;
	int pos_i, pos_j;

	direction = guard_start(map, size_i, size_j, pos_i, pos_j);

	bool left = false;
	int movement_count = 1;
	map[pos_i][pos_j] = 'X';

	while (!left)
	{
		/* draw_map(map, size_i, size_j, movement_count);
		sleep(1); */
		switch (direction)
		{
		case '^':
			if (pos_i > 0 && map[pos_i - 1][pos_j] == '#')
				direction = '>';
			else
			{
				if (map[pos_i][pos_j] == '.')
				{
					movement_count++;
					map[pos_i][pos_j] = 'X';
				}
				if (pos_i > 0)
					pos_i--;
				else
					left = true;
			}
			break;
		case '<':
			if (pos_j > 0 && map[pos_i][pos_j - 1] == '#')
				direction = '^';
			else
			{
				if (map[pos_i][pos_j] == '.')
				{
					movement_count++;
					map[pos_i][pos_j] = 'X';
				}
				if (pos_j > 0)
					pos_j--;
				else
					left = true;
			}
			break;
		case '>':
			if (pos_j < size_j - 1 && map[pos_i][pos_j + 1] == '#')
				direction = 'v';
			else
			{
				if (map[pos_i][pos_j] == '.')
				{
					movement_count++;
					map[pos_i][pos_j] = 'X';
				}
				if (pos_i < size_j - 1)
					pos_j++;
				else
					left = true;
			}
			break;
		case 'v':
			if (pos_i < size_i - 1 && map[pos_i + 1][pos_j] == '#')
				direction = '<';
			else
			{
				if (map[pos_i][pos_j] == '.')
				{
					movement_count++;
					map[pos_i][pos_j] = 'X';
				}
				if (pos_i < size_i - 1)
					pos_i++;
				else
					left = true;
			}
			break;
		default:
			map[pos_i][pos_j] = '?';
			cout << "???" << endl;
			break;
		}
	}

	return movement_count;
}

static bool guard_loop_check(char **map, int size_i, int size_j, int pos_i, int pos_j, char direction)
{
	bool left = false;
	int movement_count = 0;

	while (!left && movement_count < GUARD_LOOP_MAX)
	{
		switch (direction)
		{
		case '^':
			if (pos_i > 0 && (map[pos_i - 1][pos_j] == '#' ||
							  map[pos_i - 1][pos_j] == '@'))
				direction = '>';
			else
			{
				if (map[pos_i][pos_j] == '.')
					movement_count++;
				if (pos_i > 0)
					pos_i--;
				else
					left = true;
			}
			break;
		case '<':
			if (pos_j > 0 && (map[pos_i][pos_j - 1] == '#' ||
							  map[pos_i][pos_j - 1] == '@'))
				direction = '^';
			else
			{
				if (map[pos_i][pos_j] == '.')
					map[pos_i][pos_j] = 'X';
				if (pos_j > 0)
					pos_j--;
				else
					left = true;
			}
			break;
		case '>':
			if (pos_j < size_j - 1 && (map[pos_i][pos_j + 1] == '#' ||
									   map[pos_i][pos_j + 1] == '@'))
				direction = 'v';
			else
			{
				if (map[pos_i][pos_j] == '.')
					movement_count++;
				if (pos_i < size_j - 1)
					pos_j++;
				else
					left = true;
			}
			break;
		case 'v':
			if (pos_i < size_i - 1 && (map[pos_i + 1][pos_j] == '#' ||
									   map[pos_i + 1][pos_j] == '@'))
				direction = '<';
			else
			{
				if (map[pos_i][pos_j] == '.')
					movement_count++;
				if (pos_i < size_i - 1)
					pos_i++;
				else
					left = true;
			}
			break;
		default:
			cout << "???" << endl;
			break;
		}
	}

	return (movement_count < GUARD_LOOP_MAX);
}

int guard_loop(char **map_og, char **map_alt, int size_i, int size_j)
{
	int ret = 0, pos_i, pos_j;

	char direction = guard_start(map_og, size_i, size_j, pos_i, pos_j);

	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			if (map_alt[i][j] == 'X' && i != pos_i && j != pos_j)
			{
				map_og[i][j] = '@';
				if (guard_loop_check(map_og, size_i, size_j, pos_i, pos_j, direction))
					ret++;
				map_og[i][j] = '.';
			}
		}
	}

	return ret;
}