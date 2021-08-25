#ifndef SORT_ALG_H
#define SORT_ALG_H
#include <stdio.h>
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

/**** Bubble sort ****/
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void swap_numbers(int *a, int *b);

/**** Insertion sort ****/
listint_t *create_listint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void node_swap(listint_t *left, listint_t *right);
size_t listint_len(const listint_t *h);

/**** Selection Sort ****/
void selection_sort(int *array, size_t size);

/**** Quicksort ****/
void quick_sort(int *array, size_t size);
void quicksort_mod(int *array, int low, size_t high, size_t size);
size_t partition(int *array, int low, size_t high, size_t size);
void swap(int *a, int *b);

/*** Shellsort ****/
void shell_sort(int *array, size_t size);

/*** Heap sort ***/
void heap_sort(int *array, size_t size);
void shift_down(int *array, int size, int i, int size_array);
void swap_int(int *a, int *b);
int check_sort(int *array, int size);


#endif /* End guards sorting and searching algorithms */
