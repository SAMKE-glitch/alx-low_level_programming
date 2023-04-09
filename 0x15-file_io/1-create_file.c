#include "main.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - function that creates a file
 * @filename: name of the file
 * @text_content: the string to be printed
 * Return: sucess (1)
 */
int create_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);
	write(fd, text_content, strlen(text_content));
	close(fd);

	return (1);
}
