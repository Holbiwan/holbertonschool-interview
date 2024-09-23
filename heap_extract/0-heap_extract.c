#include "binary_trees.h"

/**
* heap_extract - Extracts the root node of a Max Binary Heap
* @root: Double pointer to root node.
* Return: Value stored in the root node
*/
int heap_extract(heap_t **root)
{
	heap_t *last_inserted_node = NULL;
	int swap;

	if (!root)
	{
		return (0);
	}

	swap = (*root)->n;
	last_inserted_node = push_to_top(*root);

	if ((*root) == last_inserted_node)
	{
		free(*root);
		*root = NULL;
		return (swap);
	}

	if (last_inserted_node->parent->right)
		last_inserted_node->parent->right = NULL;
	else
		last_inserted_node->parent->left = NULL;

	(*root)->n = last_inserted_node->n;

	heapify_down(*root);

	free(last_inserted_node);

	return (swap);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(heap_t *tree)
{
	size_t _left = 0, _right = 0;

	if (tree == NULL)
		return (0);

	else
	{
		_left = binary_tree_height(tree->left) + 1;
		_right = binary_tree_height(tree->right) + 1;
	}

	if (_left >= _right)
	{
		return (_left);
	}
	else
	{
		return (_right);
	}
}

/**
 * heapify_down - moves a node down the tree
 * @root: pointer to binary heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = NULL;
	int temp;

	if (!root)
		return;

	if (root->right)
	{
		if (root->right->n > root->left->n)
			largest = root->right;
		else
			largest = root->left;
	}
	else if (root->left)
		largest = root->left;

	if (largest && largest->n > root->n)
	{
		temp = largest->n;
		largest->n = root->n;
		root->n = temp;
		heapify_down(largest);
	}
}

/**
 * push_to_top - finds the node that goes to the top
 * @root: The root node
 * Return: Newly inserted node
 */
heap_t *push_to_top(heap_t *root)
{
	if (!root)
		return (NULL);

	if (!root->left && !root->right)
		return (root);

	if (binary_tree_height(root->left) > binary_tree_height(root->right))
		return (push_to_top(root->left));

	if (binary_tree_size(root->left) > binary_tree_size(root->right))
		return (push_to_top(root->right));

	return (push_to_top(root->right));
}


/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Siz eof tryee or 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}