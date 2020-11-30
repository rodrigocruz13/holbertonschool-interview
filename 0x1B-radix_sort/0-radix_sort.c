#include "sort.h"

/**
 * _pow_ - Returns the value of 10 ^ y
 * @y: [int] integer
 *
 * Return: The value of 10 ^ y
 */
int _pow_(int y)
{
	int result = 0;

	for (result = 1; y > 0; y--)
		result = result * 10;
	return (result);
}

/**
 * sorted - sorts the numbers in a bucket
 * @arr:  [int] array
 * @it:   [int] iterator
 * @size: [size_t] number of elements
 *
 * Return: integer
 */
int *sorted(int *arr, int it, size_t size)
{
	int i, j, digit, **buckets = NULL;
	size_t b_size = 0;

	if (!arr)
		return (NULL);

	if (size < 2)
		return (NULL);

	b_size = (size < 10) ? 10 : size;
	buckets = malloc(sizeof(int *) * b_size);
	if (!buckets)
		return (NULL);

	for (i = 0; (size_t)i < b_size ; i++)
	{   buckets[i] = malloc(sizeof(int) * 10);
		if (!buckets[i])
		{
			for (--i; i >= 0; i--)
				free(buckets[i]);
			return (NULL);
		}
		for (j = 0; j < 10; j++)
			buckets[i][j] = -1;
	}
	for (i = 0; (size_t)i < size; i++)
	{   digit = (arr[i] / _pow_(it)) % 10;
		for (j = 0; buckets[digit][j] != -1; j++)
			;
		buckets[digit][j] = arr[i];
	}
	for (i = 0, digit = 0; (size_t)i < b_size; i++)
		for (j = 0; buckets[i][j] != -1; j++)
		{   arr[digit] = buckets[i][j];
			digit++;
		}
	for (i = 0; (size_t)i < b_size; i++)
		free(buckets[i]);
	free(buckets);
	return (arr);
}

/**
 * get_max - gets the largest int in an array
 * @arr:  [int] array
 * @size: [size_t] number of elements
 *
 * Return: integer
 */
int get_max(int *arr, size_t size)
{
	int max = 0;

	for (max = arr[0], --size; size > 1; size--)
		max = arr[size] > max ? arr[size] : max;
	return (max);
}

/**
 * radix_sort - sorts an array of integers using the radix sort algorithm
 * @array:  [int] array
 * @size:   [size_t] number of elements in the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int it;
	int max;

	if (!array)
		return;

	if (size < 2)
		return;

	max = get_max(array, size);

	for (it = 0; _pow_(it) <= max; it++)
	{
		sorted(array, it, size);
		print_array(array, size);
	}
}
