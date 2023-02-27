#include "main.h"

/**
 * swap_int - swaps the value of the two integer
 * @a: int a
 * @b: int b
 */
void swap_int(int *a, int *b)
{
	int j;

	j = *a;
	*a = *b;
	*b = j;
}
