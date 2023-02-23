#include "main.h"

/**
 * print_triangle - function prints triangle to output
 * @size: integer to check
 *
 * Return: 0
 */

void print_triangle(int size)
{
	int a, b, c;

	if (size <= 0)
		_putchar('\n');
	for (a = 0; a < size; a++)
	{
		for (b = 0; (b < size - 1) - a; b++)
			_putchar(' ');
		for (c = 0; c <= a; c++)
			_putchar('#');
		_putchar('\n');
	}
}
