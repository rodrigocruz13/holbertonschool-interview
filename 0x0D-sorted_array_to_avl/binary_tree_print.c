#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s);
static size_t _height(const binary_tree_t *tree);


/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree:       Pointer to the root node of the tree to print
 *
 * Return:      Nothing
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height;
	size_t i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (1 + height));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(255 * sizeof(**s));
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < (height + 1); i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}


/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t -    Stores recursively each level in an array of strings
 *
 * @tree:       Pointer to the node to print
 * @offset:     Offset to print
 * @depth:      Depth of the node
 * @s:          Buffer
 *
 * Return:      Length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width;
	int left, right;
	int is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height -    Measures the height of a binary tree
 *
 * @tree:       Pointer to the node to measures the height
 *
 * Return:      The height (altura) of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t altura_l;
	size_t altura_r;

	altura_l = tree->left ? 1 + _height(tree->left) : 0;
	altura_r = tree->right ? 1 + _height(tree->right) : 0;
	return (altura_l > altura_r ? altura_l : altura_r);
}
