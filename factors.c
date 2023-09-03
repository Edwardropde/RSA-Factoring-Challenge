#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Function factorizes number
 * @n: number to factorize
 * Return: NULL
 */

void factorize(int n)
{

	int p, q;

	for (p = 2; p <= n / 2; ++p)
	{
		if (n % p == 0)
		{
			q = n / p;
			printf("%d=%d*%d\n", n, p, q);
			return;
		}
	}
	printf("%d is prime\n", n);
}

/**
 * main - checks code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful 1 otherwise
 */

int main(int argc, char *argv[])
{

	char line[100];
	FILE *file;
	int n;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}
	while (fgets(line, sizeof(line), file))
	{
		n = atoi(line);
		if (n <= 1)
		{
			printf("%d is not a valid natural number\n", n);
		}
		else
		{
			factorize(n);
		}
	}
	fclose(file);
	return (0);
}
