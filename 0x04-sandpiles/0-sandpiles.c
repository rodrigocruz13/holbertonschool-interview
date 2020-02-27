#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"
#define TRUE_ 1
#define FALSE_ 0

/**
 * alt_print_grid - print grid
 * @grid1: grid to print
 */
void alt_print_grid(int grid1[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - sum of 2 sandpiles
 * @grid1: 1st sandpile
 * @grid2: 2nd sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);
	if (!is_stable(grid1))
		alt_print_grid(grid1);
	while (!is_stable(grid1))
	{
		topple(grid1);
		if (!is_stable(grid1))
			alt_print_grid(grid1);
	}
}

/**
 * is_stable - Check if any cell is bigger than 3
 * @grid1: grid to be verified
 * Return:
 * @TRUE_ (1): If the grid is stable
 * @FALSE_ (0) if not.
 */
int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (FALSE_);
		}
	}
	return (TRUE_);
}

/**
 * add_grids - adds 2 grids withour restrictions
 * @grid1: grid1
 * @grid2: grid2
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
}

/**
 * topple - removes grains of sand of each cell
 * @grid1: grid
 */
void topple(int grid1[3][3])
{
	int grains[3][3];
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grains[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				/* left */
				if ((i - 1 >= 0) && (i - 1 < 3))
					grains[i - 1][j]++;
				/* right */
				if ((i + 1 >= 0) && (i + 1 < 3))
					grains[i + 1][j]++;
				/* up */
				if ((j - 1 >= 0) && (j - 1 < 3))
					grains[i][j - 1]++;
				/* down */
				if ((j + 1 >= 0) && (j + 1 < 3))
					grains[i][j + 1]++;
				grid1[i][j] -= 4;
			}
		}
	}
	add_grids(grid1, grains);
}
