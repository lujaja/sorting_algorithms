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
	merge_recursive(array, copy, 0, size);
	free(copy);
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

	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy + start, mid - start);
	printf("[right]: ");
	print_array(copy + mid, end - mid);
	i = start;
	j = mid;
	k = end;

	for (; k < end; k++)
	{
		if (i < mid && (j >= end || copy[i] <= copy[j]))
		{
			array[k] = copy[i];
			i++;
		}
		else
		{array[k] = copy[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(array + start, end - start);
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
	size_t i;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	merge_recursive(array, copy, start, mid);
	merge_recursive(array, copy, mid, end);
	merge_array(array, copy, start, mid, end);
	for (i = start; i < end; i++)
		copy[i] = array[i];
}
