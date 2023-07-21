#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array to be sorted
 * @i: The index of the first element
 * @j: The index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
	if (i != j)
	{
		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * hoare_partition - Hoare partition scheme using rightmost index as pivot;
 * other pivot implementations exist, with some with greater efficiency: see
 * pseudocode below function defs for middle or low pivot schema
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
size_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	ssize_t i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * hoare_quicksort - recursively sorts array of integers using Hoare quick sort
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 */
void hoare_quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	size_t border;

	if (low < high)
	{
		border = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, border, size);
		hoare_quicksort(array, border + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order using a quick
 * sort, Hoare partition scheme algorithm
 * @array: array of values to be printed
 * @size: number of elements in array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}
