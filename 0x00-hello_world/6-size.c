#include <stdio.h>

/**
 * main - A program that prints the size of various computer types
 * Return:0(success)
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;

printf("Size of a char:%lu byte(s)\n", (unsigned long)sizeof());
printf("Size of an int:%lu byte(s)\n", (unsigned long)sizeof());
printf("size of a long int:%lu byte(s)\n", (unsigned long)sizeof());
printf("size of a long long int:%lu byte(s)\n", (unsigned long)sizeof());
printf("size of a float:%lu byte(s)\n", (unsigned long)sizeof());
return (0);

}
