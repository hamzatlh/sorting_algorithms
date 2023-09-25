#include "sort.h"


/**
 * partition - Order array of int according to lomuto partition
 * @arr: array of integers
 * @size: size of the array.
 * @first: starting index of the subset to order
 * @last: ending index of the subset to order
 * Return: final partition index
 */
int partition(int *arr, size_t size, int first, int last)
{
	int *piv, bl, ab, temp, tmp;

	piv = arr + last;
	for (bl = ab = first; bl < last; bl++)
	{
		if (arr[bl] < *piv)
		{
			if (ab < bl)
			{
				temp = *(arr + bl);
				*(arr + bl) = *(arr + ab);
				*(arr + ab) = temp;
				print_array(arr, size);
			}
			ab++;
		}
	}
	if (arr[ab] > *piv)
	{
		tmp = *(arr + ab);
		*(arr + ab) = *piv;
		*piv = tmp;
		print_array(arr, size);
	}
	return (ab);
}

/**
 * sort - Implement quicksort algorithm through recursion
 * @arr: array of integers to sort
 * @size: size of the array
 * @first: starting index of the array partition to order
 * @last: The ending index of the array partition to order
 */
void sort(int *arr, size_t size, int first, int last)
{
	int p;

	if (last > first)
	{
		p = partition(arr, size, first, last);
		sort(arr, size, first, p - 1);
		sort(arr, size, p + 1, last);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
