#include "monty.h"
#include <stdio.h>

/**
 * push - push element onto a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	newnode = (stack_t *) malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = arg;
	newnode->prev = NULL;
	newnode->next = *stack;
	if (*stack)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 * pall - print all elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_SUCCESS);

	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * pint - print all elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	printf("pint\n");
}

/**
 * pop - print all elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	printf("pop\n");
}

/**
 * swap - print all elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	printf("swap\n");
}