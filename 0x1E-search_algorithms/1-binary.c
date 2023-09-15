#include "search_algos.h"

/**
 * binary_search - searches for a value in an integer array using a
 * binary search algorithm, not guaranteed to return index if 'value'
 * appears twice in 'array'
 * @array: pointer to first element of array to search
 * @size: the number of elements in an array
 * @value: value to search for in that array
 *
 * Return: index containing the value or -1 if value not found or array null
 */
int binary_search(int *array, size_t size, int value)
{
	int low, mid, high;
	int x;

	if (array == NULL)
	{
		return (-1);
	}

	low = 0;
	high = size - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in arra: ");
		for (x = low; x <= high; x++)
			printf("%i%s", array[x], x == high ? "\n" : ", ");

		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}
