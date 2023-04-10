#include <unistd.h>
#include "main.h"
#include <string.h>
#include <fcntl.h>

/**
 * append_text_to_file - append text to the end of the file
 * @filename: the filename
 * @text_content: the string to be added
 *
 * Return: 1 if success or -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);
	if (text_content)
	{
		write(fd, text_content, strlen(text_content));
	}
	close(fd);

	return (1);
}
