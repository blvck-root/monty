#include "monty.h"
#include <string.h>

/**
 * _atoi - convert string to integer
 * @str: string
 * @line_num: line number
 * Return: integer equivalent of string or errs out
 */
int _atoi(const char *str, unsigned int line_num)
{
	int result = 0;
	int sign = 1;
	size_t i = 0;

	if (!str)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_SUCCESS);
	}

	/* Check for leading whitespace */
	while (str[i] == ' ')
		i++;

	/* Check sign */
	if (str[i] == '+' || str[i] == '-')
	{
		sign = str[i] == '-' ? -1 : 1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	/* Check conversion success */
	if (i == strlen(str))
	{
		return (result * sign);
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
}
