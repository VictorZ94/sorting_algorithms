#include "sort.h"

/**
 * shell_sort - Sorting algorithm using knuth's sequence
 * @array: list to sort
 * @size: lenght of the arary or list
 *
 * Return: Always 0
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1, n, i;
	int value;

	if (size < 2)
		return;

	while (h < size / 3)
		h = h * 3 + 1;

	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			value = array[i];
			n = i;

			while (n > h - 1 && array[n - h] >= value)
			{
				array[n] = array[n - h];
				n -= h;
			}
			array[n] = value;
		}
		/*
		 *for (i = h; i < size; i += h)
		 *{
		 *	for (n = i; n > 0 && array[n - h] > array[n]; n -= h)
		 *		swap(&array[n - h], &array[n]);
		 *}
		 **/

		h = (h - 1) / 3;
		print_array(array, size);
	}
}
