#include "search_algos.h"

/**
 * print_array - Prints the array being searched
 * @array: array to print
 * @first: First index of the subarray
 * @last: Last index of the subarray
 */
void print_array(int *array, int first, int last)
{
	int i;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * advanced_binary - Initiates the advanced binary search algorithm
 * @array: Array to search in
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}

/**
 * recursive_search - Recursive function to search for a value in the array
 * @array: Array to search in
 * @first: First index of the subarray
 * @last: Last index of the subarray
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int recursive_search(int *array, size_t first, size_t last, int value)
{
	size_t mid;

	if (first > last)
		return (-1);

	/* Print the subarray */
	print_array(array, (int)first, (int)last);

	mid = first + (last - first) / 2;

	/* Check if mid is the value */
	if (array[mid] == value)
	{
		/* Check if it's the first occurrence */
		if (mid == first || array[mid - 1] != value)
			return ((int)mid);
		else
			return (recursive_search(array, first, mid, value));
	}

	/* If the middle element is larger, search in the left half */
	else if (array[mid] > value)
		return (recursive_search(array, first, mid - 1, value));

	/* If the middle element is smaller, search in the right half */
	else
		return (recursive_search(array, mid + 1, last, value));
}
