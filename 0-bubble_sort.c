#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorith.
 * @size: size of the array to sort
 * @array: The array
 * Return: Nothing
 * Description: Pseudocode
 * *****For ipass = 0, ipass < (length(Array) - 1), i++)
 * *************swapped = False
 * *************For (i = 0, i < (length(Array) - i - ipass), i++)
 * *********************If array[i] > array[i + 1] THEN
 * *****************************Swap
 * *****************************set swaped to True
 * *********************ENDIF
 * *************NEXT i
 * *************If swap is False
 * *********************END WHOLE PROCESS OF BUBBLE SORT
 * *************ENDIF
 * *****NEXT ipass
 * *****UNTIL swapped is FAlse
 */
void bubble_sort(int *array, size_t size)
{
	size_t ipass, i, swapped;
	int temp;

	if (size < 2)
		return;
	for (ipass = 0; ipass < (size - 1); ipass++)
	{
		swapped = 0;
		for (i = 0; i < (size - 1 - ipass); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);/*expected to*/
			}
		}
		if (swapped == 0)
			break;
	}
}
