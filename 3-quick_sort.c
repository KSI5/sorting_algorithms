#include "sort.h"

size_t lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort.
 * @array: The array of integers to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		size_t partition_index = lomuto_partition(array, low, high, size);

		if (partition_index > 0)
			quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: The array of integers to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: The index of the pivot element after partitioning.
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
