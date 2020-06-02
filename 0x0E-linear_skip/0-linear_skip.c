#include "search.h"

/**
 * linear_skip - 	implement skip list with jump = sqrt of list size
 * @list: 			head of linked list to search in
 * @value: 			number to search for
 * Return: 			node of found value or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr = list;
	skiplist_t *prev = NULL;

	size_t listSize = 0;
	size_t i = 0;

	if ((list == NULL) || (value < (list->n)))
		return (NULL);
	if ((list->n) == value)
		return (list);

	curr = list
	for (; curr != NULL; curr = curr->next, listSize++)

	curr = list;
	while ((curr != NULL) && ((curr->express != NULL) && (curr->n) < value))
	{
		prev = curr; 
		curr = curr->express;
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	}
	if ((curr->n) >= value)
		curr = prev;
	if (curr->express == NULL) 
		i = listSize - 1
	else
		curr->express->index;
	
	printf("Value found between indexes [%lu] and [%lu]\n", curr->index, i);
	for (; (curr != NULL) && (curr->n <= value); curr = curr->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n == value)
			return (curr);
	}
	return (NULL);
}
