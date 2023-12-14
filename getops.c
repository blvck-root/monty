#include "monty.h"

typedef void (*func_t)(stack_t, int);
instruction_t operations = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"nop", nop},
	{"add", add},
	{"sub", sub},
	{"div", div},
	{"mul", mul},
	{"mod", mod},
	{"rotl", rotl},
	{"rotr", rotr},
	{"pchar", pchar},
	{"pstr", pstr},
	{NULL, NULL}
};

/**
 * get_operation - get function to handle instruction
 * @opcode: name of operation
 * Return: function to handle instruction
 */
func_t get_operation(char *opcode)
{
	int i;

	for (i = 0; operations[i].opcode != NULL; i++)
	{
		if (operations[i].opcode == opcode)
			return (operations[i].f);
	}
	return (NULL);
}
