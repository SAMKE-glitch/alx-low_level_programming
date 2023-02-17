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
	int n, Last digit;
	
	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last digit = n % 10;

	if (last digit > 5)
	{
		printf("Lsat digit of %d is %d and is greator than 5\n, n, last digit);
	} else if (last digit < 6 && last digit !=0)
	{
		printf("Last digit of %d and is less than 6 and not 0\n",
				n, last digit);
	} else
		print("Last digit of %d is %d and is 0\n", n, last digit);
	return (0);
}
