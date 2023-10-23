#include "sort.h"

/**
 * _swap - Swap two numbers.
 * @n1: first integer.
 * @n2: Second integer.
 */

void _swap(int *n1, int *n2)
{
	int new;

	new = *n1;
	*n1 = *n2;
	*n2 = new;
}

/**
 * backward_insertion - Swaps two nodes in the right left position.
 * @array: The array.
 * @gap: Gap.
 * @index: actual position in the array.
 */

void backward_insertion(int *array, int gap, int index)
{
	int i;

	for (i = index - gap; i >= 0; i -= gap, index -= gap)
	{
		if (array[i] > array[index])
			_swap(&array[i], &array[index]);
		else
			break;
	}
}

/**
 * shell_sort - sort arrays of integrs in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = 0, j = gap; j < size; i++, j++)
		{
			if (array[i] > array[j])
			{
				_swap(&array[i], &array[j]);
				backward_insertion(array, gap, i);
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
