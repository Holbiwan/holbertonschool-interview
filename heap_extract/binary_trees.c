#include "binary_trees.h"

/**
 * create_node - Creates a new node
 * @parent: Pointer to the parent node
 * @n: The value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *create_node(heap_t *parent, int n)
{
    heap_t *new_node = malloc(sizeof(heap_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * _array_to_heap - Builds a max heap from an array
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: Pointer to the root of the heap
 */
heap_t *_array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL, *node;
    size_t i;

    for (i = 0; i < size; i++)
    {
        if (!root)
        {
            root = create_node(NULL, array[i]);
            continue;
        }

        node = root;
        while (1)
        {
            if (!node->left)
            {
                node->left = create_node(node, array[i]);
                break;
            }
            else if (!node->right)
            {
                node->right = create_node(node, array[i]);
                break;
            }
            node = node->left;
        }
    }

    return (root);
}

/**
 * _binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Description: This function frees all nodes in the binary tree.
 */
void _binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;

    _binary_tree_delete(tree->left);
    _binary_tree_delete(tree->right);
    free(tree);
}
