#include "menger.h"

/**
 * filled - Verifies if a pixel have to be printed
 * @col: column
 * @row: row
 * Return: 1 if filled, otherwise 0
 */

int filled(int col, int row)
{
	while (col > 0 || row > 0)
	{
		if ((col % 3 == 1) && (row % 3 == 1))
			return (0);
		col = col / 3;
		row = row / 3;
	}
	return (1);
}

/**
 * return_ - Suplementary return selector
 * @level:  level
 * Return:  0
 */
int return_(int level)
{
	if (level == -1)
		printf("#\n");
	return (0);
}

/**
 * menger - Software that prints a 2D-menger sponge
 * @level:  Levels to be printed of the 2D-menger sponge
 * Return:  Nothing
 */
void menger(int level)
{
	int floor, col, row;

	level == 0 ? return_(-1) : return_(0);

	floor = pow(3, level);
	for (col = 0; col < floor && level > 0; col++)
	{
		for (row = 0; row < floor; row++)
			filled(col, row) ? printf("%c", '#') : printf("%c", ' ');
		printf("\n");
	}
}
