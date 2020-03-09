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
	int palind = 0;

	if (head == NULL)
		return (1);

	current = *head;
	if (current == NULL)
		return (1);
	
	palind = calculate_palind(current);
		return (palind);
}

/**
 * calculate_palind- prints all elements of a listint_t list
 * @h: pointer to head of list
 * @tam: size of the linked list
 * Return: 1 if palindrome, 0 if not
 */
int calculate_palind(const listint_t *h)
{
	int i, tam;
	int *array_right = malloc(sizeof(int) * 32500);
	int *array_inverse = malloc(sizeof(int) * 32500);
	const listint_t *current = h;

	for (i = 0, tam = 0; current != NULL; current = current->next, i++, tam++)
	{
		array_right[i] = current->n;
		array_inverse[tam - i - 1] = current->n;
	}

	for (i = 0; i < tam; i++)
	{
		if (array_right[i] != array_inverse[tam - i - 1])
			return (0);
	}
	return (1);
}
