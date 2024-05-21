#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heapify_up - restores the max heap property by swapping the node with its
 * parent until the parent is greater
 * @node: pointer to the node to heapify
 * Return: pointer to the node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * insert_new_node - inserts a new node into a binary tree
 * @root: double pointer to the root node of the tree
 * @value: value to insert into the tree
 * Return: pointer to the new node, or NULL on failure
 */
heap_t *insert_new_node(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	heap_t *queue[1024];
	int head = 0, tail = 0;

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	queue[tail++] = *root;

	while (head < tail)
	{
		parent = queue[head++];
		if (parent->left == NULL)
		{
			parent->left = new_node;
			new_node->parent = parent;
			return (new_node);
		}
		else
			queue[tail++] = parent->left;

		if (parent->right == NULL)
		{
			parent->right = new_node;
			new_node->parent = parent;
			return (new_node);
		}
		else
			queue[tail++] = parent->right;
	}
	return (new_node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	new_node = insert_new_node(root, value);
	if (new_node == NULL)
		return (NULL);

	return (heapify_up(new_node));
}
