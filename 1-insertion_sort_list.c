#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * int ascending order using the insertion sort algorithm
 * @list: pointer pointer to the dlist to sort
 *
 * Return: Nothing
 * Decription:
 * For pointer Is headode AND pointer next node Is Not Null
 * ****current_node = pointer
 * ****position_node = pointer
 * ****While position_node pointer to int > current_node pointer to int
 * *********position_node = position_node pointer to prev
 * ****swap
 * UNTIL pointer to Next Is Null
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pointer, *pos_node, *temp;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	
	for (pointer = (*list)->next; pointer; pointer = temp)
	{
		temp = pointer->next;
		pos_node = pointer->prev;
		while (pointer && pointer->n < pos_node->n)
		{
			printf("%d\n", pointer->n);
		}
	}

}
