#include "main.h"

/**
 * _strncpy - function that copies string
 *
 * @dest: string where to copy to
 * @src: string to copy from
 * Return: pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	for (j = 0; j < n && src != '\0'; j++)
		dest[j] = src[j];
	for ( ; j < n; j++)
		dest[j] = '\0';
	return (dest);
}
