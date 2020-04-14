#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of ints
 * @line: Array to slide
 * @size: Size of the array
 * @direction: Direction in which to slide the array
 * Return: 0 on failure otherwise 1
 */

int slide_line(int *line, size_t size, int direction)
{
	int h_d, x, move, stop;

	if (size <= 1)
		return (0);

	if (direction == SLIDE_RIGHT)
	{	x = size - 2;
		h_d = size - 1;
		move = -1;
		stop = -1;

	}
	else if (direction == SLIDE_LEFT)
	{	x = 1;
		h_d = 0;
		move = 1;
		stop = size;
	}

	while (x != stop)
	{
		if (line[x] != 0 && line[x] == line[h_d])
		{	line[x] = 0;
			line[h_d] *= 2;
			h_d += move;
		}
		else if (line[x] != 0 && line[h_d] == 0)
		{	line[h_d] = line[x];
			line[x] = 0;
		}
		else
			h_d += move;

		if ((line[x] != 0) && (x + move == stop) && line[h_d] == 0)
		{	line[h_d] = line[x];
			line[x] = 0;
		}
		x += move;
	}
	return (1);
}
