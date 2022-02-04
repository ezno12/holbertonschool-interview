#include "sandpiles.h"

/**
 * decay - decays a sandpile and checks if new sandpile is stable
 * @grid: sandpile to evaluate
 * @i: row index
 * @j: column index
 *
 * Return: Amount of unstable elements found
 */
short decay(int grid[3][3], ssize_t i, ssize_t j)
{
	short unstbl_cnt;

	unstbl_cnt = 0;
	grid[i][j] -= 4;
	if ((j + 1) < 3)
	{
		++grid[i][j + 1];
		if (grid[i][j + 1] > 3)
			++unstbl_cnt;
	}
	if ((i + 1) < 3)
	{
		++grid[i + 1][j];
		if (grid[i + 1][j] > 3)
			++unstbl_cnt;
	}
	if ((j - 1) > -1)
	{
		++grid[i][j - 1];
		if (grid[i][j - 1] > 3)
			++unstbl_cnt;
	}
	if ((i - 1) > -1)
	{
		++grid[i - 1][j];
		if (grid[i - 1][j] > 3)
			++unstbl_cnt;
	}
	return (unstbl_cnt);
}

/**
 * stable - checks if sandpile is stable and calls decay if needed
 * @grid: sandpile to evaluate
 *
 * Return: 1 if stable, otherwise 0
 */
int stable(int grid[3][3])
{
	size_t i, j;
	int stbl;
	int backup_grid[3][3];
	static int first_call = 1;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			backup_grid[i][j] = grid[i][j];
	stbl = 1;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			if (backup_grid[i][j] > 3)
			{
				stbl = 0;
				if (!first_call && !decay(grid, i, j))
					stbl = 1;
			}
	first_call = 0;
	return (stbl);
}

/**
 * print_grid - prints a grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_grids - sums two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			grid1[i][j] += grid2[i][j];
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);
	while (!stable(grid1))
	{
		puts("=");
		print_grid(grid1);
	}
}
