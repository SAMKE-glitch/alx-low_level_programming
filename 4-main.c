#include <stdio.h>

/**
 * main - storing the address of a variable into a pointer
 *
 * Return: always 0
 */
int main(void)
{
	int n;
	int *p;
	 n = 98;
	 p = &n;

	 printf("Address value of 'n': %p\n", &n);
	 printf("The value of 'p': %p\n", p);
	 return (0);
}
