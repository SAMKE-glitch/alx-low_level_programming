#include <stdio.h>

/**
 * main - function that prints the number of arguments
 * @argc: argc parameter
 * @argv: an array fo a command
 * Return: sucess (0)
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
