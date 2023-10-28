#include "sort.h"

/**
 * swap_root_node - A function that swaps the root nodes.
 * @root: The root of the heap.
 * @high: The higher index.
 * @array: The heap to sort.
 * @size: The size of the array
 * Return: Nothing.
 */

void swap_root_node(int *array, size_t root, size_t high, size_t size)
{
	size_t low = 0, mid = 0, temp = 0;
	int i = 0;

	while ((low = (2 * root + 1)) <= high)
	{
		temp = root;
		mid = low + 1;
		if (array[temp] < array[low])
			temp = low;
		if (mid <= high && array[temp] < array[mid])
			temp = mid;
		if (temp == root)
			return;
		array[root] = array[temp];
		array[temp] = i;
		print_array(array, size);
		root = temp;
	}
}

/**
 * heap_sort - A function that sorts an array using heap sort.
 * @array: An array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */

void heap_sort(int *array, size_t size)
{
	size_t high = 0, gap = 0;
	int i = 0;

	if (array == NULL || size < 2)
		return;
	for (gap = (size - 2) / 2; 1; gap--)
	{
		swap_root_node(array, gap, size - 1, size);
		if (gap == 0)
			break;
	}
	high = size - 1;
	while (high > 0)
	{
		i = array[high];
		array[high] = array[0];
		array[0] = i;
		print_array(array, size);
		high--;
		swap_root_node(array, 0, high, size);
	}
}
