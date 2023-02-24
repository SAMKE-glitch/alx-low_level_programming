#include "main.h"

/**
 * print_number - function that prints an integer
 * @n: the integer to print
 */

void print_number(int n)
{
	if (n == 0)
		_putchar('0');
	else if (n < 0)
	{
		_putchar('_')
			print_integer(n * -1);
	}
	else
		print_integer(n);
}
