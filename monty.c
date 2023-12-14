#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - interpret monty byte code
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: 0 if success else 1
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char **tokens, *line = NULL;
	size_t line_num = 0, len = 0;
	ssize_t i, nread;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		++line_num;
		/* detect instructions and execute code */
		tokens = tokenize(line, "$ \n\t\r\v\f");
		if (!tokens)
		{
			fprintf(stderr, "Line %ld - Error: something bad happened\n", line_num);
			exit(EXIT_FAILURE);
		}

		command = tokens[0];
		if (strcmp(command, "push") == 0)
			arg = _atoi(tokens[1]);
		execute_op(get_operation(command), line_num);
	}
	free(line);
	free(tokens);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
