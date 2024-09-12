#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the array being searched
 * @array: array to print
 * @low: starting index
 * @high: ending index
 */
void print_array(int *array, size_t low, size_t high)
{
    size_t i;

    printf("Searching in array: ");
    for (i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches for a value in a sorted
 *                             array of integers using binary search
 * @array: The array to search
 * @low: The starting index of the search range
 * @high: The ending index of the search range
 * @value: The value to search for
 * Return: The index of the first occurrence of the value, or -1
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
    size_t mid;

    if (low > high)
        return (-1);

    print_array(array, low, high);

    mid = (low + high) / 2;

    if (array[mid] == value)
    {
        if (mid == low || array[mid - 1] != value)
        {
            // When we find the value, ensure we continue to print the remaining portion correctly
            if (mid + 1 <= high && array[mid + 1] == value)
                return (advanced_binary_recursive(array, mid + 1, high, value));
            return (mid);
        }
        else
            return (advanced_binary_recursive(array, low, mid - 1, value));
    }
    else if (array[mid] > value)
        return (advanced_binary_recursive(array, low, mid - 1, value));
    else
        return (advanced_binary_recursive(array, mid + 1, high, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   using a binary search algorithm
 * @array: The array to search
 * @size: The size of the array
 * @value: The value to search for
 * Return: The index of the first occurrence of the value, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
