#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define BUFSIZE 256
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
	char *line;
	int line_count = 0;
	char **cmd;

	if (argc < 2 || argc > 2) /*Check for argument count*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bytefile = fopen(argv[1], "r");
	if (bytefile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(BUFSIZE + 1);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, BUFSIZE, bytefile) != NULL) /*Read and parse lines*/
	{
		line_count++;
		cmd = parse_buf(line);
		if (cmd[1] == NULL)
			printf("ln[%d]: %s\n", line_count, cmd[0]);
		else
			printf("ln[%d]: %s %s\n", line_count, cmd[0], cmd[1]);
	}
	free(line);
	fclose(bytefile);

	return (0);
}

/**
 * parse_buf - Removes any leading and trailing whitespaces
 * from bytecode
 *
 * @line: Pointer to line buffer
 *
 * Return: An array with the parsed commands, consisting
 * of the opcode and it's arguments
 */
char **parse_buf(char *line)
{
	static char *tokens[2];

	tokens[0] = strtok(line, " \t\n");
	tokens[1] = strtok(NULL, " \t\n");

	return (tokens);
}
