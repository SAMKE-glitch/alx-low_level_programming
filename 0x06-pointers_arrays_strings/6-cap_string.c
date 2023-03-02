#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 *
 * @z: string parameter
 * Return: capitalized version of string
 */
char *cap_string(char *z)
{
	char spc[] = {32, 9, '\n', ',', ';', '.', '!', '?', '"', '(', ')', '{', '}'};

	int len = 13;

	int a = 0, i;

	while (z[a])
	{
		i = 0;
		while (i < len)
		{
			if ((a == 0 || z[a - 1] == spc[i]) && (z[a] >= 97 && z[a] <= 122))
			z[a] = z[a] - 32;
			i++;
		}
		a++;
	}
	return (Z);
}
