#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>

/* 
 * print_array - Prints an array of integers
 * @array: The array to print
 * @size: Number of elements in the array
 */
void print_array(const int *array, size_t size);

/* 
 * merge_sort - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size);

#endif /* SORT_H */
