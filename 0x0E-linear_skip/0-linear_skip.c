#include "search.h"

/**
 * linear_skip -	implement skip list with jump = sqrt of list size
 * @list:			head of linked list to search in
 * @value:			number to search for
 * Return:			node of found value or NULL if not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *now;
	skiplist_t *prev;
	char *msg1 = "Value checked at index";
	char *msg2 = "Value found between indexes";

	if (!list)
		return (NULL);

	prev = list;
	now = list->express;
	while (now)
	{
		printf("%s [%lu] = [%d]\n", msg1, now->index, now->n);
		if (now->n >= value)
			break;
		prev = now;
		if (!now->express)
		{
			while (now->next)
				now = now->next;
			break;
		}
		now = now->express;
	}
	printf("%s [%lu] and [%lu]\n", msg2, prev->index, now->index);
	while (prev && prev->index <= now->index)
	{
		printf("%s [%lu] = [%d]\n", msg1, prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
