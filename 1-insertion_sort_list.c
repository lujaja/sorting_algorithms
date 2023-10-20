#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * int ascending order using the insertion sort algorithm
 * @list: pointer pointer to the dlist to sort
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = *list;
	curr = curr->next;

	while (curr)
	{
		while (curr->prev && curr->n < (curr->prev)->n)
		{
			temp = curr;
			if (curr->next)
				(curr->next)->prev = temp->prev;
			(curr->prev)->next = temp->next;
			curr = curr->prev;
			temp->prev = curr->prev;
			temp->next = curr;
			if (curr->prev)
				(curr->prev)->next = temp;
			curr->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			curr = curr->prev;
		}
		curr = curr->next;
	}
}
