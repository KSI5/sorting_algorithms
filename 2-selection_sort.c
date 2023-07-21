#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using
 * the Selection sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_j, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		min_j = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min_j])
				min_j = j;
		}

		if (min_j != i)
		{
			temp = array[i];
			array[i] = array[min_j];
			array[min_j] = temp;
			print_array(array, size);
		}
	}
}
