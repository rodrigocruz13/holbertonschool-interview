#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome- prints all elements of a listint_t list
 * @listint_t: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
    const listint_t *current;
    unsigned int n; /* number of nodes */
    int palind = 0;

    current = *head;

    // Calulate size
    if (current != NULL)
        n = size_listint(current);
    if (n > 0)
    {
        palind = calculate_palind(current, n);
        return (palind);
    }
    return (0);
}

int calculate_palind(const listint_t *h, int n)
{
    int i;
    int* array_right = malloc(sizeof(int)*n);
    int* array_inverse = malloc(sizeof(int)*n);
    const listint_t *current = h;


    for (i = 0; current != NULL; current = current->next, n++)
    {
        array_right[i] = current->n;
        array_inverse[n - i - 1] = current->n;
    }

    for (i = 0; i < n; i++)
    {
        if (array_right[i] != array_inverse[n - i - 1])
            return (0);
    }
    return (1);
}



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
