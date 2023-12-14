#include "monty.h"

/**
 * execute_op - run a command
 * @f: command handler
 * Return: void
 */
void execute_op(void (*f) (stack_t, int))
{
	f(top, line_num);
}
