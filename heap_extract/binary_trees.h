#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Basic Binary Tree */
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
void binary_tree_print(const binary_tree_t *tree);

/* New function prototypes */
heap_t *_array_to_heap(int *array, size_t size);
void _binary_tree_delete(binary_tree_t *tree);
heap_t *create_node(heap_t *parent, int n);

#endif /* BINARY_TREES_H */
