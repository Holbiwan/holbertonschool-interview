#include "binary_trees.h"

/**
 * swap_nodes - Swap the values between two nodes
 * @a: The first node
 * @b: The second node
 *
 * Description: This function swaps the values stored in two nodes.
 */
void swap_nodes(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * last_node - Find the last node in the heap using level-order traversal
 * @root: The root of the heap
 *
 * Return: Pointer to the last node in the heap
 *
 * Description: This function finds the last node in the heap by
 * using a queue to perform a level-order traversal.
 */
heap_t *last_node(heap_t *root)
{
    heap_t *last = NULL;
    heap_t **queue;
    int front = 0, rear = 0, size = 1024;

    queue = malloc(size * sizeof(heap_t *));
    if (!queue)
        return (NULL);

    queue[rear++] = root;

    while (front < rear)
    {
        last = queue[front++];
        if (last->left)
            queue[rear++] = last->left;
        if (last->right)
            queue[rear++] = last->right;
    }

    free(queue);
    return (last);
}

/**
 * sift_down - Rebuild the heap by sifting down the new root
 * @root: The root of the heap
 *
 * Description: This function ensures that the heap property is maintained
 * by moving the new root down to its correct position in the heap.
 */
void sift_down(heap_t *root)
{
    heap_t *largest = root;

    while (1)
    {
        if (root->left && root->left->n > largest->n)
            largest = root->left;
        if (root->right && root->right->n > largest->n)
            largest = root->right;

        if (largest == root)
            break;

        swap_nodes(root, largest);
        root = largest;
    }
}

/**
 * heap_extract - Extract the root node of a max binary heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 if the function fails
 *
 * Description: This function removes the root node of the heap, replaces
 * it with the last node, and ensures the heap property is maintained.
 */
int heap_extract(heap_t **root)
{
    heap_t *last;
    int extracted_value;

    if (!root || !*root)
        return (0);

    extracted_value = (*root)->n;

    /* If there's only one node, free it and return the value */
    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    last = last_node(*root);
    swap_nodes(*root, last);

    /* Remove last node */
    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    free(last);
    sift_down(*root);

    return (extracted_value);
}
