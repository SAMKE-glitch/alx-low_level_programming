#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint -  converts binary to unsigned int
 * @b: contains address our string to be converted
 *
 * Return: converted number, or 0 if b is NULL, if there's
 * one or more chars in string that is not 0 and 1
 */
unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int r = 0;
	
	if (b == NULL)
		return (0);

	for (; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		r = r  << 1;

		if (b[i] == '1')
			r = r | 1;
	}

	return (r);
}
