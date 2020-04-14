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
	size_t aux, mark = 0, p1 = 0, p2 = 1, t1, t2;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	p1 = (direction == SLIDE_RIGHT) ? size - 1 : p1;
	p2 = (direction == SLIDE_RIGHT) ? size - 2 : p2;

	for (t1 = 0; t1 < size; t1++)
	{       aux = p2;
		mark = 0;
		for (t2 = t1 + 1; t2 < size; t2++)
		{
			if (line[p1] != 0 && line[p2] == line[p1])
			{	line[p1] = line[p1] * 2;
				line[p2] = 0;
				break; }

			if (line[p1] == 0 && line[p2] != 0)
			{	line[p1] = line[p2];
				line[p2] = 0;
				mark = 1;
				p2 = aux;
				t1--;
				break; }

			if (line[p2] != 0)
				break;
			direction == SLIDE_LEFT ? p2++ : p2--;
		}
		if (line[p1] == 0)
			break;
		if (mark == 0)
		{	p1 = (direction == SLIDE_LEFT) ? p1 + 1 : p1;
			p1 = (direction == SLIDE_RIGHT) ? p1 - 1 : p1;
			p2 = (direction == SLIDE_LEFT) ? p1 + 1 : p2;
			p2 = (direction == SLIDE_RIGHT) ? p1 - 1 : p2; }
	}
	return (1);
}
