#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node: The node to be swapped.
 */

void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending.
 *
 * @list: Double pointer to the head of the list.
 */

void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *new;

	if (list == NULL || *list == NULL)
		return;
	new = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (new->next != NULL)
		{
			if (new->next->n < new->n)
			{
				swap_nodes(list, new);
				swapped = 1;
				print_list(*list);
			}
			else
				new = new->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (new->prev != NULL)
		{
			if (new->prev->n > new->n)
			{
				swap_nodes(list, new->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				new = new->prev;
		}
	}
}
