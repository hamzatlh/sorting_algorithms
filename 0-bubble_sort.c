#include "sort.h"
#include <stdbool.h>

/**
 * swapint - Swap two integers in an array
 * @i: first integer to swap
 * @j: second integer to swap
 */
void swapint(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		bubble = true;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapint(array + j, array + j + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		if (bubble)
			break;
	}
}
