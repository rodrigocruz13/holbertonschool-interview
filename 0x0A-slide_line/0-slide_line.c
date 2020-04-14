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
	size_t p1 = 0, p2 = 1, tmp1, tmp2, aux1, flag = 0;

	if (direction != SLIDE_RIGHT && direction != SLIDE_LEFT)
		return (0);

	p1 = (direction == SLIDE_RIGHT) ? size - 1 : p1;
	p2 = (direction == SLIDE_RIGHT) ? size - 2 : p2;

	for (tmp1 = 0; tmp1 < size; tmp1++)
	{   flag = 0;
		aux1 = p2;
		for (tmp2 = tmp1 + 1; tmp2 < size; tmp2++)
		{
			if (line[p2] == line[p1] && line[p1] != 0)
			{	line[p1] = 2 * line[p1];
				line[p2] = 0;
				break;
			}
			if (line[p2] == 0 && line[p1] != 0)
			{	line[p1] = line[p2];
				line[p2] = 0;
				flag = 1;
				p2 = aux1;
				tmp1 = tmp1 - 1;
				break;
			}
			if (line[p2] != 0)
				break;
			direction == SLIDE_LEFT ? p2++ : p2--;
		}
		if (line[p1] == 0)
			break;
		if (flag == 0)
		{	p1 = (direction == SLIDE_LEFT) ? p1 + 1 : p1;
			p1 = (direction == SLIDE_RIGHT) ? p1 - 1 : p1;
			p2 = (direction == SLIDE_LEFT) ? p1 + 1 : p2;
			p2 = (direction == SLIDE_RIGHT) ? p1 - 1 : p2; }
	}
	return (1);
}
