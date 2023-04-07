#include "main.h"

/**
 * flip_bits - returns number of bits needed to be flipped
 * @n: variable containing bits to be used
 * @m: variable containing bits to be used
 *
 * Return: flipped bits counted
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int bit_t;
	int count = 0;
	int i;

	bit_t = n ^ m;

	if (bit_t == 0)
		return (-1);
	for (i = 0; i < 64; i++)
	{
		count += bit_t & 1;
		bit_t = bit_t >> 1;
	}
	return (count);
	return (0);
}
