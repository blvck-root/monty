#include "monty.h"
#include <string.h>

/**
 * is_integer - check if string can be converted to integer
 * @str: string
 * Return: 1 if str can be converted to int, else -1
 */
int is_integer(const char *str)
{
	size_t i = 0;

	if (!str)
		return (1);

	if (str[0] == '+' || str[0] == '-')
		++i;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		++i;
	}
	return (0);
}

/**
 * check_instruction - check if an instruction is valid
 * @opcode: instruction string
 * @arg: string argument
 * @stack: stack on which the instruction will be executed
 * @line_num: line number
 * Return: -1 if error, else 1
 */
int check_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_num)
{
	if (strcmp("push", opcode) == 0)
	{
		if (is_integer(arg) == 0)
			return (0);
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		return (1);
	}
	else if (strcmp("pall", opcode) == 0 || strcmp("nop", opcode) == 0)
	{
		return (0);
	}
	else if (strcmp("pint", opcode) == 0)
	{
		if (stack != NULL && *stack != NULL)
			return (0);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		return (1);
	}
	else if (strcmp("pop", opcode) == 0)
	{
		if (stack != NULL && *stack != NULL)
			return (0);
		fprintf(stderr, "L%u: can't pop en empty stack\n", line_num);
		return (1);
	}
	else if (strcmp("swap", opcode) == 0)
	{
		if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
			return (0);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		return (1);
	}
	else if (strcmp("add", opcode) == 0)
	{
		if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
			return (0);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		return (1);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
		return (1);
	}
}
