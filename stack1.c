#include "monty.h"
#include <stdio.h>

/**
 * _add - add top 2 elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int tmp;
	(void) line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;	
	tmp = node->next->n;
	node->next->n = node->n + tmp;
	pop(stack, line_number);
}
