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
	size_t i, tam;
    int array[1000000];
    listint_t *temp;

    temp = *head;
    if (temp == NULL)
        return (1);

	if (temp != NULL)
	{
		for (tam = 0; temp != NULL; temp = temp->next, tam++)
            array[tam] = temp->n;
	}
    for (i = 0; i < tam / 2; i++)
    {
        if (array[i] != array [tam - i - 1])
            return(0);
    }
    return (1);
}
