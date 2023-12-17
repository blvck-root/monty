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
	char *instruction, *str_arg = NULL, *line = NULL;
	char *delim = "$ \n\t\r\v\f";
	unsigned int line_num = 0;
	int status = 0;
	size_t len = 0;
	ssize_t nread;
	stack_t *top = NULL;
	instruction_t operations[24] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{NULL, NULL}
	};

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
		instruction = strtok(line, delim);
		if (!instruction)
		{
			continue; /* do nothing if line is empty */
		}
		str_arg = strtok(NULL, delim);
		status = execute_op(instruction, str_arg, operations, &top, line_num);
	}

	free(line);
	free_stack(top);
	fclose(stream);
	exit(status);
}
