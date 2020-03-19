#include "lists.h"

/**
 * check_cycle - check the linked list if is a cycle or not.
 * @list: is the linked list.
 * Return: Always 0.
 */

int check_cycle(listint_t *list)
{
	listint_t *ptr1, *ptr2;

	if (!list)
		return (0);

	ptr1 = list;
	ptr2 = list->next;

	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		if (!ptr1)
			return (0);
		
        ptr2 = ptr2->next;
		if (!ptr2)
			return (0);
		
        ptr2 = ptr2->next;
		if (!ptr2)
			return (0);
	}
	return (1);
}
