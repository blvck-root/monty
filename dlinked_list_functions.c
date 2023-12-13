#include "monty.h"

/**
 * add_node - adds a new item to the beginning of list.
 * @head: pointer to the first node.
 * @n: the data element of the node.
 * Return: the address of the new node.
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp = *head;
	new_node->n = n;
	new_node->next = temp;
	new_node->prev = NULL;
	if (temp != NULL)
		temp->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * free_stack - frees a linked list.
 * @head: pointer to the first node.
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
