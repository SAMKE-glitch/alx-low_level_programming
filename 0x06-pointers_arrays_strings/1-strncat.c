#include "main.h"
#include <string.h>
/**
 * _strncat - join two strings upto n bytes
 *
 * @dest: where to be copied to
 * @src: where to be copied from
 * @n: upto n bytes
 * Return: Pointer
 */
char *_strncat(char *dest, char *src, int n)
{
	strncat(dest, src, n);
	return (dest);
}
