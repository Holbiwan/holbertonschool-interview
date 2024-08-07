#include "binary_trees.h"
#include <stdlib.h> // Include for memory allocation

/**
 * binary_tree_node - Creates a new AVL tree node.
 *
 * @parent: Pointer to the parent node.
 * @index: Index of the current element in the array.
 * @array: Pointer to the array of integers.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
avl_t *binary_tree_node(avl_t *parent, size_t index, int *array)
{
    avl_t *new_node;

    new_node = malloc(sizeof(avl_t));
    if (!new_node)
        return (NULL);

    new_node->left = NULL;       // Initialize left child
    new_node->right = NULL;      // Initialize right child
    new_node->n = array[index];  // Set the value of the node
    new_node->parent = parent;   // Set the parent pointer

    return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}

/**
 * sorted_array_to_avl_helper - Recursively builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * @parent: Pointer to the parent node.
 *
 * Return: Pointer to the root node of the created AVL subtree, or NULL on failure.
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    size_t mid = (start + end) / 2;

    // Create a new node with the middle element
    avl_t *new_node = binary_tree_node(parent, mid, array);
    if (!new_node)
        return (NULL);

    // Recursively build the left subtree
    new_node->left = sorted_array_to_avl_helper(array, start, mid - 1, new_node);

    // Recursively build the right subtree
    new_node->right = sorted_array_to_avl_helper(array, mid + 1, end, new_node);

    return (new_node);
}
