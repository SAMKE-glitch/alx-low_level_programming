#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 Always Success
 */

int main(void)
{

	int n;
	
	for (n = 48; n <= 57; n++)
	{
	
		putchar(n);
		if (n !=57)
		{
		
			putchar(',');
			putchar(' ');
		}
		
	}
	putchar ('\');
	return (0);
}
