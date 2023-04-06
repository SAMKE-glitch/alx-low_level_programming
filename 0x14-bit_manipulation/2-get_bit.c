#include "main.h"
#include <stdio.h>

/**
 * get_bit - gets bit at index index
 * @n: unsigned long int containing bits
 * @index: the index that have the bit to return
 * Return: -1 if there's an error or the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index >= 64)
	{
		return (-1);
	}

	bit = (n >> index) & 1;

	return (bit);

}
