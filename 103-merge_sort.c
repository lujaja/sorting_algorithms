#include "sort.h"

/**
 * merge_sort - Sorts an array into ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *copy = NULL;
	size_t j = 0;

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (; j < size; j++)
		copy[j] = array[j];
	merge_recursive(array, copy, 0, size - 1);
	free(copy);
}

/**
 * merge_recursive - Recursively sorts the array using merge sort.
 * @array: The original array.
 * @copy: A copy of the array for merging.
 * @start: The start index of the current subarray.
 * @end: The end index of the current subarray.
 */

void merge_recursive(int *array, int *copy, size_t start, size_t end)
{
	size_t mid = 0;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_recursive(array, copy, start, mid);
		merge_recursive(array, copy, mid + 1, end);
		merge_array(array, copy, start, mid, end);
	}
}	

/**
 * merge_array - Merges two sorted subarrays.
 * @array: The original array.
 * @copy: A copy of the array.
 * @start: The start index of the first subarray.
 * @mid: The end index of the first subarray.
 * @end: the end index of the second subarray.
 */

void merge_array(int *array, int *copy, size_t start, size_t mid, size_t end)
{
	size_t i = 0, j = 0, k = 0;

	i = start;
	j = mid + 1;

	for (k = start; k <= end; k++)
	{
		if (i <= mid && (j > end || copy[i] <= copy[j]))
		{
			array[k] = copy[i];
			i++;
		}
		else
		{
			array[k] = copy[j];
			j++;
		}
	}
}
