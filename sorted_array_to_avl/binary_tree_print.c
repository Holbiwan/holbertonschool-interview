#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Recursively stores each level of a binary tree in a buffer
 *
 * @tree: Pointer to the current node of the tree to print.
 * @offset: Horizontal offset for printing the current node.
 * @depth: Depth of the current node in the tree.
 * @s: Buffer to store the string representation of the tree.
 *
 * Return: Total width of the printed subtree.
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6]; // Buffer for node representation
    int width, left, right, is_left, i;

    if (!tree) // If the node is NULL, return 0 (no width)
        return (0);

    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);

    // Recursively print the left and right subtrees
    left = print_t(tree->left, offset, depth + 1, s);
    right = print_t(tree->right, offset + left + width, depth + 1, s);

    // Copy the formatted string into the buffer at the appropriate position
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    // Draw connecting lines for left children
    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    // Draw connecting lines for right children
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }

    return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree starting at @tree.
 */
static size_t _height(const binary_tree_t *tree)
{
    size_t height_l;
    size_t height_r;

    if (!tree)
        return (0);

    // Calculate the height of left and right subtrees recursively
    height_l = tree->left ? 1 + _height(tree->left) : 0;
    height_r = tree->right ? 1 + _height(tree->right) : 0;

    // Return the larger of the two heights
    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree.
 *
 * @tree: Pointer to the root node of the tree to print.
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height, i, j;

    if (!tree) // Check if the tree is empty
        return;

    height = _height(tree); // Calculate the height of the tree

    // Allocate memory for the array of strings
    s = malloc(sizeof(*s) * (height + 1));
    if (!s)
        return;

    // Allocate memory for each line of the tree and initialize with spaces
    for (i = 0; i < height + 1; i++)
    {
        s[i] = malloc(sizeof(**s) * 255); // 255 is chosen for maximum width
        if (!s[i])
        {
            // Free previously allocated memory in case of failure
            for (size_t k = 0; k < i; k++)
                free(s[k]);
            free(s);
            return;
        }
        memset(s[i], 32, 255); // Fill with spaces
    }

    print_t(tree, 0, 0, s); // Call the recursive print function

    // Print each line of the tree and free the memory
    for (i = 0; i < height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
