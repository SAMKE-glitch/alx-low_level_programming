#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * read_textfile - reads text file and prints to POSIX std output
 * @filename: name of the file to read
 * @letters: letters to be read and printed
 *
 * Return: number of letters to be read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t lenr, lenw;
	char *ch;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ch = malloc(sizeof(char) * letters);
	if (ch == NULL)
	{
		close(fd);
		return (0);
	}
	lenr = read(fd, ch, letters);
	close(fd);
	if (lenr == -1)
	{
		free(ch);
		return (0);
	}
	lenw = write(STDOUT_FILENO, ch, lenr);
	free(ch);
	if (lenr != lenw)
		return (0);

	return (lenw);
}
