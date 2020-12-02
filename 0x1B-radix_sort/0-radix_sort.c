#include "sort.h"

/**
 * _max - Finds the maximum integer in an array
 * @array: Array where the max number will be found
 * @size: Siz of @array
 * Return: Max Number
 */

int _max(int *array, int size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
		max = (array[i] > max) ? array[i] : max;
	return (max);
}

/**
 * _count - Sort the array digit by digit depending on exp
 * @array: Array that will be sorted
 * @size: Size of @array
 * @exp: Integer by which array[i] will be divided to find specific digit.
 * Return: nothing
 */

void _count(int *array, int size, int exp)
{
	int i, *output, count[10] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Store occurrences of each digit in the count position */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i], it can save current pos of the digit in output[] */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/** Store each value in its respective index in output[] */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/** Pass output[] to array[] with the number correctly sorted */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}


/**
 * radix_sort - Sorts an array of integers in ascending order using the LSD
 * radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of @array
 * Return: nothing
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2)
		return;

	for (max = _max(array, size), exp = 1; max / exp > 0; exp *= 10)
	{
		_count(array, size, exp);
		print_array(array, size);
	}
}
