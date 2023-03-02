#include "main.h"

/**
 * reverse_array - function that reverses an array
 * @a array to be reversed
 * @n: number of elements of the array
 * Return: 0
 */
void reverse_array(int *a, int n)
{
	int i, tmp;

	for (i = 0; i < n / 2; i++)
	{
		tmp = a[n - i - 1];
		a[n - i - 1] = a[i];
		a[i] = tmp;
	}
}
