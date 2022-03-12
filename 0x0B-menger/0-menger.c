#include "menger.h"

/**
 * menger - draws a 2D menger sponge
 * @level: number of levels to draw
 * Return: nothing
 */
void menger(int level)
{
	int col, row, size;

	if (level < 0)
		return;
	size = pow(3, level);
	for (col = 0; col < size; col++)
	{
		for (row = 0; row < size; row++)
			printf("%c", hash_space(col, row));
		putchar(10);
	}
}


/**
 * hash_space - gets a character
 * @col: column
 * @row: row
 * Return: '#' or ' '
 */
char hash_space(int col, int row)
{
	while (col && row)
	{
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
		col /= 3, row /= 3;
	}
	return ('#');
}
