#ifndef MONTY_H
#define MONTY_H


#define MAX_TOKEN 256

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct token_s - Structure for a token.
 * @value: the value of the token or opcode.
 * @type: field to represent the type of token.
 */
typedef struct token_s
{
	char *value;
	int type;
} Token;

/* external variables */
extern int arg;
extern int line_number;
extern stack_t top;
extern instruction_t operations[];

/* prototypes */
typedef void (*func_t)(stack_t, int);
func_t get_operation(char *opcode);
stack_t *add_node(stack_t **head, const int n);
FILE *check_file(int ac, char *av[]);

/* helper functions */
char **tokenize(char *str, char *delim);
int _atoi(char *str);
void execute_op(funct_t f);

#endif
