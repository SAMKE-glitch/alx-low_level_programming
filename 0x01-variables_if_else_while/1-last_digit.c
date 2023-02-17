#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 Always success
 */

int main(void)
{
	int n, Lastdigit;
	
	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastdigit = n % 10;

	if (lastdigit > 5)
	{
		printf("Lat digit of %d is %d and is greator than 5\n, n, lastdigit);
	} else if (lastdigit < 6 && lastdigit !=0)
	{
		printf("Last digit of %d and is less than 6 and not 0\n",
				n, lastdigit);
	} else
		print("Last digit of %d is %d and is 0\n", n, lastdigit);
	return (0);
}
