#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int arg;

/**
 * main - interpret monty byte code
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: 0 if success else 1
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *instruction, **tokens, *line = NULL;
	unsigned int line_num = 0;
	/*int arg = 0;*/
	stack_t *top = NULL;
	size_t len = 0;
	ssize_t nread;

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
		tokens = tokenize(line, "$ \n\t\r\v\f");
		if (!tokens[0])
		{
			continue; /* do nothing if line is empty */
		}

		instruction = tokens[0];
		if (strcmp(instruction, "push") == 0)
			arg = _atoi(tokens[1], line_num);
		execute_op(instruction, &top, line_num);
	}

	free(line);
	free(tokens);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
