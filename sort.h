#ifndef SORT_H
#define SORT_H
/******************************************************
 * Collaborators:                                     *
 * 	Lujaja Luvuga <jarzcyber@gmail.com> [Kenyan]  *
 * 	Edith Banda                         [Malawian *
 * ****************************************************/

/***********************************
 * Standard C Library Header Files *
 * *********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/*********************************
 * Data Structures and Functions *
 * *******************************/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/**********************
 * Function Protoypes *
 * ********************/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_nodes(listint_t **h, listint_t **next_node, listint_t *prev_node);
int lomutopartition(int *array, size_t, int, int);
void sort(int *a, size_t, int, int);

/**************************************
 * Advanced Tasks Function prototypes *
 * ************************************/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/******************
 * Swap operation *
 * ****************/
void swap(int *i, int *j);

#endif /*SORT_H*/
