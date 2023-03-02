#include "main.h"

/**
 * string_toupper - function that changes uppercase to lowercase
 * @c: string to be changed
 * Return: a lowercase characer or string.
 */
char *string_toupper(char *c)
{
	int i = 0;

	while (c[i] != '\0'; i++)
	{
		if (c[i] >= 97 && c[i] <= 122)
			c[i] = c[i] - 32;
	}
	return (c);

}
