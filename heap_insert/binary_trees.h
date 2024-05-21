#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
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

/* Function prototype for the print function */
void binary_tree_print(const binary_tree_t *);

/* Function prototype for creating a new binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Function prototype for inserting a value into a Max Binary Heap */
heap_t *heap_insert(heap_t **root, int value);

#endif /* BINARY_TREES_H */
