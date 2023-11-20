#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * factorize - The function factorize a number
 * @buffer: pointer to the address of the number
 *
 * Return: int
 */
int factorize(char *buffer)
{

	long num;
	long i;

	num = atoi(buffer);


	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%ld=%ld*%ld\n", num, num / i, i);
			break;
		}
	}

	return (0);
}


/**
 * main - main function
 *
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	size_t count;
	ssize_t line;
	char *buffer = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buffer, &count, fptr)) != -1)
	{
		factorize(buffer);
	}
	return (0);
}
