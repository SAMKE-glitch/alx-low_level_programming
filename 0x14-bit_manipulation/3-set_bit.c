#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at index
 * @n: points to unsigned long int
 * @index: the index that is beeing accessed
 * Return: 1 if it worked or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	int bit_t;
	int i;

	if (index > 64)
		return (-1);
	for (i = 0; i < 64; i++)
	{
		bit_t = 1 << index;
		*n = *n | bit_t;
	}
	return (1);
}
