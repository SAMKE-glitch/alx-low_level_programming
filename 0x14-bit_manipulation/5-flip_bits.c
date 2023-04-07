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
	unsigned long int bit_t;
	unsigned long int count = 0;

	bit_t = n ^ m;

	while (bit_t != 0)
	{
		count += bit_t & 1;
		bit_t = bit_t >> 1;
	}
	return (count);
}
