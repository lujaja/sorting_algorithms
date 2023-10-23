#include "sort.h"

/**
 * shell_sort - sort arrays of integrs in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int i, j, gap, tmp;
	size_t n = size;

	gap = 1;

	while (gap <= n / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < n; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap]
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
