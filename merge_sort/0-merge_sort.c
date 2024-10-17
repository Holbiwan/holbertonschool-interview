#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of array in sorted order.
 * @array: The original array to be sorted.
 * @temp: A temporary buffer for merging.
 * @start: The starting index of the first subarray.
 * @mid: The middle index of the first subarray.
 * @end: The ending index of the second subarray.
 */
void merge(int *array, int *temp, int start, int mid, int end)
{
    int left_iter = start, right_iter = mid + 1, array_iter = start;

    /* Print the merging process */
    printf("Merging...\n");
    printf("[left]: ");
    print_array(&array[start], mid - start + 1);
    printf("[right]: ");
    print_array(&array[mid + 1], end - mid);

    /* Merge the subarrays back into the temporary array */
    while (left_iter <= mid && right_iter <= end)
    {
        if (array[left_iter] <= array[right_iter])
            temp[array_iter++] = array[left_iter++];
        else
            temp[array_iter++] = array[right_iter++];
    }

    /* Copy remaining elements of the left subarray if any */
    while (left_iter <= mid)
        temp[array_iter++] = array[left_iter++];

    /* Copy remaining elements of the right subarray if any */
    while (right_iter <= end)
        temp[array_iter++] = array[right_iter++];

    /* Copy the sorted subarray back into the original array */
    for (array_iter = start; array_iter <= end; array_iter++)
        array[array_iter] = temp[array_iter];

    /* Print the result of the merging */
    printf("[Done]: ");
    print_array(&array[start], end - start + 1);
}

/**
 * split_arrays - Recursively splits the array and merges subarrays.
 * @array: Pointer to the array of integers.
 * @temp: A temporary buffer for merging.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 *
 * Return: None.
 */
void split_arrays(int *array, int *temp, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        /* Recursively split and sort the left and right subarrays */
        split_arrays(array, temp, start, mid);
        split_arrays(array, temp, mid + 1, end);

        /* Merge the sorted subarrays */
        merge(array, temp, start, mid, end);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge Sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 *
 * Return: None.
 */
void merge_sort(int *array, size_t size)
{
    if (array && size >= 2)
    {
        /* Allocate a temporary buffer for merging */
        int *temp = malloc(size * sizeof(int));

        if (temp == NULL)
            return;  /* Handle allocation failure */

        /* Split and merge the array */
        split_arrays(array, temp, 0, size - 1);

        /* Free the temporary buffer */
        free(temp);
    }
}
