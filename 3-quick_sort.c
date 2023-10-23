#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array to sort
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
/**
 * lomutopartition - function to do the partitioning precess
 * @a: array to partition
 * @first: parameter 1
 * @last: parameter 2
 * @size: parameter 3
 *
 * Return: pivot element position
 */
int lomutopartition(int *a, size_t size, int first, int last)
{
	int i, j;

	i = first - 1;

	for (j = first; j <= last - 1; j++)
	{
		if (a[j] < a[last])
		{
			i++;
			if (i < j)
			{
				swap(&a[i], &a[j]);
				print_array(a, size);
			}
		}
	}
	if (a[i + 1] > a[last])
	{
		swap(&a[i + 1], &a[last]);
		print_array(a, size);
	}
	return (i + 1);
}

/**
 * sort - recursive sorting function
 * @a: array to sort
 * @low: lower bound
 * @high: higher bound
 * @size: array size
 *
 * Return: Nothing
 */
void sort(int *a, size_t size, int low, int high)
{
	int partition;

	if (low < high)
	{
		partition = lomutopartition(a, size, low, high);
		sort(a, size, low, partition - 1);
		sort(a, size, partition + 1, high);
	}
}

/**
 * swap - function to swap elements
 * @i: element 1
 * @j: element 2
 *
 * Return: Nothing
 */
void swap(int *i, int *j)
{
	 int tmp;

	 tmp = *i;
	 *i = *j;
	 *j = tmp;
}
