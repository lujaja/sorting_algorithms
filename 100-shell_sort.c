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
	int i, j, gap, tmp, n;

	n = (int) size;
	gap = 1;

	while (gap <= (n - 1) / 9)
		gap = 3 * gap + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < n; i++)
		{
			tmp = array[i];
			for (j = i; j > 0; j = i - gap)
			{
				if (array[j] < array[j - gap])
					array[j] = array[j - gap];
				else
					break;
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
