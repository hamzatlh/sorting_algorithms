#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *m, temp;
	size_t a, b;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		m = array + a;
		
		for (b = a + 1; b < size; b++)
		{
			m = (array[b] < *m ? (array + b) : m);
		}
		if ((array + a) != m)
		{
			temp = *(array + a);
			*(array + a) = *m;
			*m = temp;
			print_array(array, size);
		}
	}
}
