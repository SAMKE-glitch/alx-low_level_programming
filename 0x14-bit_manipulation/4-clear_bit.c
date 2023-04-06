#include "main.h"

/**
 * clear_bit - set the value of a bit to 0 at a given index
 * @n: pointing ot our unsigned long int
 * @index: the index to be accessed
 * Return: 1 if it worked or -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	int i;
	int bit_t;

	if (index > 64)
		return (-1);
	for (i = 0; i < 64; i++)
	{
		bit_t = 1 << index;
		*n = *n & ~bit_t;
	}
	return (1);
}
