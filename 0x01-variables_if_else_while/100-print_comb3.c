#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 Always
 */

int main(void)
{

	int n, b, c;

	for (n = 48; n <=57; n++)
	{
	
		for(b = n + 1; b <= 57; b++)
		{
		
			for (c = b + 1; c <= 57; c++)
			{
			
				putchar(n);
				putchar(b);
				putchar(c);
				if (n !=55 || b !=56 || c !=57)
				{
				
					putchar(',');
					putchar(' ');
				}

			}
		
		}
	
	}
	putchar('\n');
	return (0);
}
