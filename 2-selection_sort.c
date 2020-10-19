#include "sort.h"

/**
 * selection_sort - Sorting array through selection sort method
 * @array: it's the array to sort
 * @size: it's size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_num;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_num = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[min_num] > array[j])
				min_num = j;

		}
		if (min_num != i)
		{
			swap_numbers(&array[i], &array[min_num]);
			print_array(array, size);
		}
	}
}

/**
 * swap_numbers - function to swap two number
 * @a: first number to swap
 * @b: second number to swap
 *
 * Return: Nothing
 */
void swap_numbers(int *a, int *b)
{
	int change = 0;

	change = *a;
	*a = *b;
	*b = change;
}
