#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
		int n;
		struct binary_tree_s *parent;
		struct binary_tree_s *left;
		struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
heap_t *my_sorting(heap_t *node);
int heap_extract(heap_t **root);
void my_order(heap_t *root, heap_t **node, size_t height, size_t floor);


#endif /* _BINARY_TREES_H_ */
