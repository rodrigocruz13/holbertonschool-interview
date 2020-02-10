#include "lists.h"

/**
 * insert_node - Adds a new_node number in a listint_t list.
 * @number: number to be added in the list
 * @head:   pointer at the head of the list
 *
 * Return: "The address of the new_node element, or NULL if it failed"
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *tmp, *ant;
	unsigned int i = 0;

	if (head == NULL)
		return (0);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	if (*head == NULL)
	{
		new_node->n = number, new_node->next = NULL, *head = new_node;
		return (new_node);
	}
	for (tmp = *head, new_node->n = number;
		 new_node->n > tmp->n && tmp != NULL;
		 ant = tmp, tmp = tmp->next, i++)
	{
		if (tmp->next == NULL)
			break;
	}
	if (tmp->next != NULL)
	{
		if (i != 0)
		{
			ant->next = new_node, new_node->next = tmp;
		}
		else
		{
			new_node->next = *head, *head = new_node;
		}
	}
	else
	{
		tmp->next = new_node, new_node->next = NULL;
	}
	return (new_node);
}
