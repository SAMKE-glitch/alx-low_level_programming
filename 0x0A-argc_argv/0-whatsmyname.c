#include <stdio.h>

/**
 * main - function to print its name
 * @argc: parameter
 * @argv: array of a command
 * Return: 0 for success
 */
int main (int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
