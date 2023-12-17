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

	newnode->n = n;
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
	stack_t *node;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't print, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	printf("%d\n", node->n);
}

/**
 * pop - print all elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	*stack = node->next;
	if (node->next)
	{
		(*stack)->prev = NULL;
		node->next = NULL;
	}
	free(node);
}


/**
 * swap - print all elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int tmp;
	(void) line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	tmp = node->n;
	node->n = node->next->n;
	node->next->n = tmp;
}
