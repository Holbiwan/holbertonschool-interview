#include "sort.h"

/**
 * _swap - Swaps two values in an array and prints the array after swapping
 * @array: The array in which to swap values
 * @i: First index
 * @j: Second index
 * @orig_size: Original size of the array for printing
 */
void _swap(int *array, int i, int j, const int orig_size)
{
	int tmp;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)orig_size);
	}
}

/**
 * _heapify - Ensures the max heap property for a subtree
 * @array: The array to sort
 * @size: The size of the subtree
 * @i: The root index of the subtree
 * @orig_size: Original size of the array for printing
 */
void _heapify(int *array, size_t size, int i, const int orig_size)
{
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		_swap(array, i, largest, orig_size);
		_heapify(array, size, largest, orig_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	const int orig_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		_heapify(array, size, i, orig_size);

	/* Extract elements from heap one by one */
	for (i = size - 1; i > 0; i--)
	{
		_swap(array, 0, i, orig_size);  /* Move current root to end */
		_heapify(array, i, 0, orig_size);  /* Call heapify on the reduced heap */
	}
}
