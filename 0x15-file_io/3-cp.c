#include <stdio.h>
#include "main.h"

/**
 * error_file - checks if files can be opened
 * @from: file from
 * @to: file_to
 * @argv: arguments vector
 *
 * Return: no return
 */
void error_file(int from, int to, char *argv[])
{
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code if copied successfully
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int from, to, er_clse;
	ssize_t nch, nwr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(from, to, argv);

	nch = 1024;
	while (nch == 1024)
	{
		nch = read(from, buffer, 1024);
		if (nch == -1)
			error_file(-1, 0, argv);
		nwr = write(to, buffer, nch);
		if (nwr == -1)
			error_file(0, -1, argv);
	}
	er_clse = close(from);
	if (er_clse == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	er_clse = close(to);
	if (er_clse == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	return (0);
}
