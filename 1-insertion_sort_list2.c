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
	listint_t *prev_node, *next_node, *temp;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	for (next_node = (*list)->next; next_node; next_node = temp)
	{
		temp = next_node->next;
		prev_node = next_node->prev;
		while (prev_node != NULL && next_node->n < prev_node->n)
		{
			swap_nodes(list, &prev_node, next_node);
			print_list((const listint_t *) *list);
		}
	}
}

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list
 * @h: a pointer to the head
 * @next_node: pointer pointer
 * @prev_node: pointer
 */
void swap_nodes(listint_t **h, listint_t **next_node, listint_t *prev_node)
{
	(*next_node)->next = prev_node->next;
	if (prev_node->next != NULL)
		prev_node->next->prev = (*next_node);
	prev_node->prev = (*next_node)->prev;
	prev_node->next = (*next_node);
	if ((*next_node)->prev != NULL)
		(*next_node)->prev->next = prev_node;
	else
		*h = prev_node;
	(*next_node)->prev = prev_node;
	*next_node = prev_node->prev;
}
