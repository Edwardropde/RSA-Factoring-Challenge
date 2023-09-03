#include <stdio.h>
#include <stdlib.h>

/**
 * is_prime - check number if is prime
 * @n: number to be checked:
 * Return: 0 if it is prime 1 if otherwise
 */

int is_prime(long long n)
{

	long long i;

	if (n <= 1)
	{
		return (0);
	}
	for (i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * factor_rsa_number - Factorize rsa number
 * @n: Number to factorize
 * Return: Nothing
 */

void factor_rsa_number(long long n)
{

	long long p;
	long long q;

	for (p = 2; p <= n; ++p)
	{
		if (is_prime(p) && n % p == 0)
		{
			q = n / p;
			if (is_prime(q))
			{
				printf("%lld=%lld*%lld\n", n, p, q);
				return;
			}
		}
	}
}

/**
 * main - Check code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful 1 if otherwise
 */

int main(int argc, char *argv[])
{

	long long n;

	if (argc != 2)
	{
		printf("Usage: %s <number>\n", argv[0]);
		return (1);
	}
	n = atoll(argv[1]);
	if (n <= 1)
	{
		printf("%lld is not a valid natural number\n", n);
		return (1);
	}
	factor_rsa_number(n);
	return (0);
}
