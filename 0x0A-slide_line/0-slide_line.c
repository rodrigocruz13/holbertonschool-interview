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
	size_t pos1 = 0, pos2 = 1, temp1, temp2, aux1, flag = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	pos1 = (direction == SLIDE_RIGHT) ? size - 1 : pos1;
	pos2 = (direction == SLIDE_RIGHT) ? size - 2 : pos2;

	for (temp1 = 0; temp1 < size; temp1++)
	{       aux1 = pos2;
		flag = 0;
		for (temp2 = temp1 + 1; temp2 < size; temp2++)
		{
			if (line[pos1] != 0 && line[pos2] == line[pos1])
			{	line[pos1] = line[pos1] * 2;
				line[pos2] = 0;
				break; }

			if (line[pos1] == 0 && line[pos2] != 0)
			{	line[pos1] = line[pos2];
				line[pos2] = 0;
				flag = 1;
				pos2 = aux1;
				temp1--;
				break; }

			if (line[pos2] != 0)
				break;
			direction == SLIDE_LEFT ? pos2++ : pos2--;
		}
		if (line[pos1] == 0)
			break;
		if (flag == 0)
		{	pos1 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos1;
			pos1 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos1;
			pos2 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos2;
			pos2 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos2; }
	}
	return (1);
}
