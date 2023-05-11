#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Program's entry point
 *
 * @argc: Argument count
 * @argv: Arguments
 *
 * Return: 0 on success, otherwise, EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} else
	{
		printf("Yaay!, one argument: %s\n", argv[1]);
	}

	return (0);
}
