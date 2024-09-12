#include "search_algos.h"

/**
 * print_array - Prints the array being searched
 * @array: Array to print
 * @first: First index of the array to print
 * @last: Last index of the array to print
 */
void print_array(int *array, int first, int last)
{
	int i;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%d, ", array[i]);
	printf("%d", array[i]);
	printf("\n");
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   using an advanced binary search algorithm
 * @array: The array to search
 * @size: The size of the array
 * @value: The value to search for
 * Return: The index of the first occurrence of the value, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}

/**
 * recursive_search - Recursive function to perform advanced binary search
 * @array: The array to search
 * @first: The first index of the current sub-array
 * @last: The last index of the current sub-array
 * @value: The value to search for
 * Return: The index of the first occurrence of the value, or -1
 */
int recursive_search(int *array, size_t first, size_t last, int value)
{
	size_t mid;

	if (first < last)
	{
		mid = first + (last - first) / 2;
		print_array(array, (int)first, (int)last);
		if (array[mid] >= value)
			return (recursive_search(array, first, mid, value));
		else
			return (recursive_search(array, mid + 1, last, value));
	}

	/* Final base case where the first equals the last */
	print_array(array, (int)first, (int)last);
	if (array[first] == value)
		return (first);
	return (-1);
}
