#include <stdio.h>

/**
 * Main - entry point
 * Return: 0
 */

int main(void)
{
	unsigned long n = 612852475143;
	unsigned long factor = 2;

	while (n > factor)
		if (n % factor == 0)
			n /= factor;
		else
			factor++;
	printf("%lu\n", factor);
	return (0);
}
