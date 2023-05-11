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
	FILE *bytefile;

	/* Check for argument count */
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*
	 * Try opening the file, if for any reason file doesn't
	 * open, print an error to stderr
	 */
	bytefile = fopen(argv[1], "r");

	if (bytefile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("File opens successfully\n");

	fclose(bytefile);

	return (0);
}
