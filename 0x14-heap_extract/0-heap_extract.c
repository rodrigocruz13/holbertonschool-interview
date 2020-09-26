#include "binary_trees.h"

/**
 * my_height -			Function that returns the height of a tree
 * @tree:				Head of a binary tree
 * Return:				The height of the tree starting from the head
 */

size_t my_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;
	size_t height = 0;

	if (tree->left)
		height_l = 1 + my_height(tree->left);
	else
		height_l = 0;

	if (tree->right)
		height_r = 1 + my_height(tree->right);
	else
		height_r = 0;

	if (height_l > height_r)
		height = height_l;
	else
		height = height_r;

	return (height);
}

/**
 * my_order -			Walks a binary tree
 * @root:				Pointer to root of the tree
 * @node:				Pointer to node in the tree
 * @height:				Height tree
 * @floor:				Current floor
 **/

void my_order(heap_t *root, heap_t **node, size_t height, size_t floor)
{
	if (!root)
		return;
	if (height == floor)
		*node = root;
	floor = floor + 1;

	if (root->left)
		my_order(root->left, node, height, floor);

	if (root->right)
		my_order(root->right, node, height, floor);
}

/**
 * my_sorting -			Sorts a binary tree
 * @node:				Pointer to the root
 * Return:				Pointer to node
 **/

heap_t *my_sorting(heap_t *node)
{
	int number_at_node;

	while (node->left || node->right)
	{
		if (!node->right || node->left->n > node->right->n)
		{
			number_at_node = node->n;
			node->n = node->left->n;
			node->left->n = number_at_node;
			node = node->left;
		}
		else if (!node->left || node->left->n < node->right->n)
		{
			number_at_node = node->n;
			node->n = node->right->n;
			node->right->n = number_at_node;
			node = node->right;
		}

	}
	return (node);
}

/**
 * heap_extract -		Extracts the root node
 * @root:				Pointer to the root
 * Return:				Value
 **/

int heap_extract(heap_t **root)
{
	int value;
	int height;
	int floor;

	heap_t *temp, *node;

	floor = 0;
	if (!root || !*root)
		return (floor);

	temp = *root;
	value = temp->n;
	if (!temp->right && !temp->left)
	{
		*root = NULL;
		free(temp);
		return (value);
	}

	floor = 0;
	height = my_height(temp);
	my_order(temp, &node, height, floor);
	temp = my_sorting(temp);
	temp->n = node->n;

	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);

	return (value);
}
