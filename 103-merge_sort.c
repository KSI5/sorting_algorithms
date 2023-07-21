#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays into a single sorted array
 * @array: The original array
 * @left: Pointer to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_size: Size of the right sub-array
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	temp = malloc(sizeof(int) * (left_size + right_size));
	if (temp == NULL)
		return;

	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0, k = 0; i < left_size + right_size; i++, k++)
		array[i] = temp[k];

	free(temp);
	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * merge sort algorithm (Top-down approach)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, array, mid, array + mid, size - mid);
}
