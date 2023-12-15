#include "monty.h"
#include <string.h>

/**
 * execute_op - handle instruction
 * @opcode: name of operation
 * @top: pointer to the top of a stack
 * @line_num: line number
 * Return: void
 */
void execute_op(char *opcode, stack_t **top, unsigned int line_num)
{
	int i;
	instruction_t operations[24] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	(void) arg;

	for (i = 0; operations[i].opcode != NULL; i++)
	{
		if (strcmp(operations[i].opcode, opcode) == 0)
		{
			operations[i].f(top, line_num);
			break;
		}
	}

	if (operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}
