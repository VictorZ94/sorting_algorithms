#include "sort.h"

/**
 * heap_sort - Sort an array method
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
        int i;

        if (array == NULL)
                return;

        if (check_sort(array, (int)size))
	{
		print_array(array, size);
                return;
	}

        for (i = size / 2 - 1; i >= 0; i--)
                shift_down(array, size, i, size);

        for (i = size - 1; i > 0; i--)
        {
                swap_int(&array[0], &array[i]);
                print_array(array, size);
                shift_down(array, i, 0, size);
        }
}

/**
 * shift_down - shift down method
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @i: Initialize largest as root
 * @size_array: Number of elements in @array real
 *
 * Return: Nothing
 */
void shift_down(int *array, int size, int i, int size_array)
{
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && array[l] > array[largest])
                largest = l;

        if (r < size && array[r] > array[largest])
                largest = r;

        if (largest != i)
        {
                swap_int(&array[i], &array[largest]);
                print_array(array, size_array);
                shift_down(array, size, largest, size_array);
        }
}

/**
 * check_sort - check whether array is sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: 1 on success, otherwise 0
 */
int check_sort(int *array, int size)
{
        int i;

        for (i = 0; i < size - 1; i++)
        {
                if (array[i] > array[i + 1])
                        return (0);

        }
        return (1);
}

/**
 * swap_int - Swap two numbers.
 * @a: Argument pointer to int
 * @b: Argument pointer to int
 *
 * Return: Nothing
 */
void swap_int(int *a, int *b)
{
        int c;

        c = *b;
        *b = *a;
        *a = c;
}
