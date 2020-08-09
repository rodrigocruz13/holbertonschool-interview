#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n:		  Integer
 * @index:	  Index of the node in the list
 * @next:	   Pointer to the next node
 * @express:	Pointer to the next node in the express lane
 *
 * Description: Singly linked
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *create_skiplist(int *array, size_t size);

#endif /* SEARCH_H */
