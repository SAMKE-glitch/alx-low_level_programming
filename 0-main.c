#include <stdio.h>

/**
 * main - using size of dynamically determine the size of types of char, int and float
 *
 * Return: always 0
 */

int main(void)
{

	int n;
	printf("Size of type 'char' on my computer: %lu bytes\n", sizeof(char));
	printf("Size of type 'int' on my computer: %lu bytes\n", sizeof(int));
	printf("Size of type 'float' on my computer: %lu bytes\n", sizeof(float));
	printf("Size of my variable n on my computer: %lu bytes\n", sizeof(n));
	return (0);
}
