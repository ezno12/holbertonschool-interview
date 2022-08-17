#include "sort.h"
/**
 * swap - swaps two positions
 * @array1: array1
 * @array2: array2
 * Return: is a void
 */
void swap(int *array1, int *array2)
{
	int tmp;

	tmp = *array1;
	*array1 = *array2;
	*array2 = tmp;
}
/**
 * heap - makes array into a heap
 * @array: ptr to int array
 * @size: size of array
 * @mp: max point
 * @length: size of the array in heap_sort fn
 * Return: is a void
 */
void heap(int *array, int size, int mp, int length)
{
	int max = mp;
	int left = (2 * mp) + 1;
	int right = (2 * mp) + 2;

	if (left < size && array[max] < array[left])
		max = left;

	if (right < size && array[max] < array[right])
		max = right;

	if (max != mp)
	{
		swap(&array[mp], &array[max]);
		print_array(array, length);
		heap(array, size, max, length);
	}
}

/**
 * heap_sort - sort and array (heap method)
 * @array: array to sort
 * @size: size of array
 * Return: is a void
 */
void heap_sort(int *array, size_t size)
{
	int mp;

	if (!size || !array)
		return;
	for (mp = (size / 2) - 1; mp >= 0; mp--)
		heap(array, size, mp, size);

	for (mp = size - 1; mp > 0; mp--)
	{
		if (array[0] >= array[mp])
		{
			swap(&array[0], &array[mp]);
			print_array(array, size);
		}
		heap(array, mp, 0, size);
	}
}
