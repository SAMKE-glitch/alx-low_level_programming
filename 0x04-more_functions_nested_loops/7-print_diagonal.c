#include "main.h"

/**
 * print_diagonal - prints diagonal line on the terminal
 * @n: integer to check
 * Return: 0
 */

void print_diagonal(int n)
{
	int a, b;

	if (n <= 0)
		_putchar('\n');
	for (a = 0; a < n; a++)
	{
		for (b = 0; b <= a - 1; b++)
		{
			_putchr(' ');
		}
		_putchar('\\');
		_putchar('\n');
	}
}
