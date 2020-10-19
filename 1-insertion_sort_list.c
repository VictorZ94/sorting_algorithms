#include "sort.h"

/**
 * insertion_sort_list - sorting algorithm method insert sort.
 * @list: first node to overhead.
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *aux;
	short flag = 0;

	if (listint_len(*list) < 2)
		return;

	while (1)
	{
		tmp = *list;
		aux = (*list)->next;
		while (aux != NULL)
		{
			if (tmp->n > aux->n)
			{
				if (tmp->prev == NULL)
				{
					tmp->next->prev = NULL;
					tmp->next = aux->next;
					if (aux->next != NULL)
						aux->next->prev = tmp;
					aux->next = tmp;
					tmp->prev = aux;
					*list = aux;
					print_list(*list);
				}
				else
				{
					node_swap(tmp, aux);
					print_list(*list);
				}
				break;
			}
			else
			{
				if (aux->next != NULL)
				{
					aux = aux->next;
					tmp = tmp->next;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
			break;
	}
}

/**
 * node_swap - Function swaps two nodes
 * @left: first node to swap
 * @right: second node to swap
 *
 * Return: Nothing
 */
void node_swap(listint_t *left, listint_t *right)
{

	if (right->next == NULL)
	{
		left->next->prev = left->prev;
		left->next = NULL;
		left->prev->next = right;
		right->next = left;
		left->prev = right;
	}
	else
	{
		left->next = right->next;
		left->prev->next = right;
		right->prev = left->prev;
		right->next->prev = left;
		right->next = left;
		left->prev = right;
	}
}

/**
 * listint_len - prints amount of nodes linked list of integers.
 * @h: List or arguments
 *
 * Return: Numbers of nodes.
 */
size_t listint_len(const listint_t *h)
{
	if (h == NULL)
		return (0);

	return (1 + listint_len(h->next));
}
