#include "sort.h"

/**
 * radix_sort - radix sort algorithm in c
 * @array: pointer to array to be sorted
 * @size: size of array
 * Return: Nothing
 **/

void radix_sort(int *array, size_t size)
{
	size_t i, k;
	int ix, bucket[10][10], b_cnt[10], j, r, op, div = 1, lar, pass;

	if (size < 2)
		return;

	for (lar = array[0], i = 1; i < size; i++)
		lar = (array[i] > lar) ? array[i] : lar;

	for (op = 0; lar > 0; lar /= 10)
		op++;

	for (pass = 0; pass < op; pass++)
	{
		for (i = 0; i < size; i++)
			b_cnt[i] = 0;

		for (i = 0; i < size; i++)
		{
			r = (array[i] / div) % 10;
			bucket[r][b_cnt[r]] = array[i];
			b_cnt[r] += 1;
		}

		for (ix = 0, k = 0; k < 10; k++)
		{
			for (j = 0; j < b_cnt[k]; j++, ix++)
				array[ix] = bucket[k][j];
		}

		div *= 10;
		print_array(array, size);
	}
}
