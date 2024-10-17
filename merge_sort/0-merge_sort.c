#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of array in sorted order.
 * @array: The original array to be sorted.
 * @start: The starting index of the first subarray.
 * @mid: The middle index of the first subarray.
 * @end: The ending index of the second subarray.
 */
void merge(int *array, int start, int mid, int end)
{
    int left_iter, right_iter, array_iter;
    int left_size = mid - start + 1;
    int right_size = end - mid;

    /* Allocate memory for left and right subarrays */
    int *left = malloc(left_size * sizeof(int));
    int *right = malloc(right_size * sizeof(int));

    if (!left || !right)
        return;  /* Handle allocation failure */

    /* Copy data to the left and right subarrays */
    for (left_iter = 0; left_iter < left_size; left_iter++)
        left[left_iter] = array[start + left_iter];
    for (right_iter = 0; right_iter < right_size; right_iter++)
        right[right_iter] = array[mid + 1 + right_iter];

    /* Merge the subarrays back into the original array */
    left_iter = right_iter = 0;
    array_iter = start;

    while (left_iter < left_size && right_iter < right_size)
    {
        if (left[left_iter] <= right[right_iter])
        {
            array[array_iter] = left[left_iter];
            left_iter++;
        }
        else
        {
            array[array_iter] = right[right_iter];
            right_iter++;
        }
        array_iter++;
    }

    /* Copy remaining elements of left subarray if any */
    while (left_iter < left_size)
    {
        array[array_iter] = left[left_iter];
        left_iter++;
        array_iter++;
    }

    /* Copy remaining elements of right subarray if any */
    while (right_iter < right_size)
    {
        array[array_iter] = right[right_iter];
        right_iter++;
        array_iter++;
    }

    /* Print the merging process */
    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    printf("[Done]: ");
    print_array(&array[start], left_size + right_size);

    /* Free the dynamically allocated memory */
    free(left);
    free(right);
}

/**
 * split_arrays - Recursively splits the array and merges subarrays.
 * @array: Pointer to the array of integers.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 *
 * Return: None.
 */
void split_arrays(int *array, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        /* Recursively split and sort the left and right subarrays */
        split_arrays(array, start, mid);
        split_arrays(array, mid + 1, end);

        /* Merge the sorted subarrays */
        merge(array, start, mid, end);
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
        split_arrays(array, 0, size - 1);
    }
}
