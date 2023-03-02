#include "main.h"

/**
 * _strcat - concatinates 2 strings
 * @dest: destination str
 * @src: source str
 * Return: The destiantion str
 */
char *_strcat(char *dest, char *src)
{
	int i, k;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (k = 0; src[k]; k++)
		dest[i++] = src[k];
	dest[i++] = '\0';

	return (dest);
}
