#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - free stack
 * @stack: stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		free(stack);
	else
		free_stack(stack->next);
}
