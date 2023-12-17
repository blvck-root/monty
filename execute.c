#include "monty.h"
#include <string.h>

int n = 0;

/**
 * get_instruction - get instruction object
 * @opcode: string representation of an instruction
 * @operations: array of instructions to search
 * Return: instruction object, or NULL
 */
instruction_t get_instruction(char *opcode, instruction_t operations[])
{
	int i;

	for (i = 0; operations[i].opcode != NULL; i++)
	{
		if (strcmp(operations[i].opcode, opcode) == 0)
			return (operations[i]);
	}
	return (operations[i]);
}

/**
 * execute_op - handle instruction
 * @line: text line from file
 * @top: pointer to the top of a stack
 * @line_num: line number
 * Return: void
 */
int execute_op(char *opcode, char *arg, instruction_t operations[], stack_t **stack, unsigned int line_num)
{
	instruction_t instruction;

	if (check_instruction(opcode, arg, stack, line_num) == 1)
		return (1); /* execution failed */
	
	/* execute instruction if valid */
	n = arg == NULL ? 0 : atoi(arg);
	instruction = get_instruction(opcode, operations);
	instruction.f(stack, line_num);
	return (0);
}
