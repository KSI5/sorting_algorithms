#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array containing the elements
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * heapify - Recursive function to create a max heap
 * @array: The array to be sorted
 * @size: Size of the array
 * @root: Index of the root of the sub-tree
 * @total_size: Total size of the array (for printing)
 */
void heapify(int *array, size_t size, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(array, root, largest);
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
