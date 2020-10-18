#include "sort.h"

/**
 * bubble_sort - method to sort an array
 * @array: it's the array to sort
 * @size: it's size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_numbers(&array[j], &array[j + 1]);
				print_array(array, size);
			}
			else
				flag++;
		}
		if (flag == (size - 1))
			break;
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
