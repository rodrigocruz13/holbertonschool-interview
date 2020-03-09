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
	unsigned int n; /* number of nodes */
	int palind = 0;

	
	if (head == NULL)
		return (0);

	current = *head;
	if (current == NULL)
		return (0);
	
	n = size_listint(current);
	if (n == 0)
		return (1);

	else
	{
		palind = calculate_palind(current, n);
		return (palind);
	}
	return (0);
}

/**
 * calculate_palind- prints all elements of a listint_t list
 * @h: pointer to head of list
 * @tam: size of the linked list
 * Return: 1 if palindrome, 0 if not
 */
int calculate_palind(const listint_t *h, int tam)
{
	int i;
	int *array_right = malloc(sizeof(int) * tam);
	int *array_inverse = malloc(sizeof(int) * tam);
	const listint_t *current = h;

	for (i = 0; current != NULL; current = current->next, i++)
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

/**
 * size_listint- calculates the size of a listint_t list
 * @h: pointer to head of list
 * Return: The size of a list
 */
size_t size_listint(const listint_t *h)
{
	const listint_t *current;
	unsigned int n; /* number of nodes */

	current = h;
	for (n = 0; current != NULL; current = current->next, n++)
	{
	}
	return (n);
}
