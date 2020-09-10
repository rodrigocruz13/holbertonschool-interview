#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	int array[] = {0, 1, 2, 5, 5, 6, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("\nFind 8\n");
	printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
	printf("\nFind 5\n");
	printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
	printf("\nFind 999\n");
	printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
	return (EXIT_SUCCESS);
}
