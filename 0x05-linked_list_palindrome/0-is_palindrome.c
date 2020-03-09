#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome- prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	const listint_t *current;
	int i, tam;
	int array_right[32000];
	int array_inverse[32000];

	current = *head;

	for (i = 0, tam = 0; current != NULL; current = current->next, i++, tam++)
	{
		array_right[i] = current->n;
		array_inverse[tam - i - 1] = current->n;
	}

	if (current == NULL || tam < 2)
		return (1);

	for (i = 0; i < tam; i++)
	{
		if (array_right[i] != array_inverse[tam - i - 1])
			return (0);
	}
	return (1);
}
