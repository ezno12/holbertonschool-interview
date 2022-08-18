#include "search.h"
/**
 * advanced_binary - advanced binary search
 *
 * @array: pointer
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the first index, or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	int half = ((size - 1) / 2), result = 0;
	size_t i = 0;

	if (array == NULL || size < 1)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != (size - 1))
			printf(", ");
		else
			printf("\n");
	}

	if (array[half] == value && half == 0)
		return (half);
	else if (size == 1)
		return (-1);

	if (array[half] >= value)
		return (advanced_binary(array, half + 1, value));

	half++;
	result = advanced_binary(&array[half], size - half, value);
	if (result == -1)
		return (-1);
	return (half + result);
}
