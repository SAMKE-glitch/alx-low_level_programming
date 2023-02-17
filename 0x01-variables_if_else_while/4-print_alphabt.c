#include <stdio.h>

/**
 * main - Function
 *
 * Return: 0 Always Success
 */

int main(void)
{

	int n;

	for (n = 97; n<= 122; n++)
		if (n == 113 || n == 101)
			;
		else
			putchar(n);
	putchar('\n');
	return (0);
}
