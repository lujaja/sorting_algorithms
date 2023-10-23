#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int max = 0, i, *sorted_array, *count = NULL;
	size_t j, temp, output = 0;

	if (array == NULL || size < 2)
		return;

	for (j = 0 ; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (j = 0; j < size; j++)
		count[array[j]] += 1;
	for (i = 1; i <= max; i++)
	{
		temp = count[i];
		count[i] = output;
		output += temp;
	}
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count);
		return;
	}
	for (j = 0; j < size; j++)
	{
		sorted_array[count[array[j]]] = array[j];
		count[array[j]] += 1;
	}
	for (j = 0; j < size; j++)
	{
		array[j] = sorted_array[j];
	}
	print_array(count, max + 1);
	free(count);
	free(sorted_array);
}
