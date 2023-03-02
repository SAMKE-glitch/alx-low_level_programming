#include "main.h"
#include <string.h>

/**
 * _strncpy - function that copies string
 *
 * @dest: string where to copy to
 * @src: string to copy from
 * Return: pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	strncpy(dest, src, n);
	return (dest);
}
