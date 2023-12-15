#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * contains - check if a string contains a certain character
 * @str: string
 * @c: character
 * Return: 1 if char is found, otherwise return -1
 */
int contains(char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (-1);
}

/**
 * count_toks - count the number of tokens in a string
 * @str: string
 * @delim: delimiter
 * Return: number of tokens
 */
size_t count_toks(char *str, char *delim)
{
	size_t i, num_tokens = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 || str[i + 1] == '\0')
			continue;

		if (contains(delim, str[i]) == 1)
		{
			if (contains(delim, str[i + 1]) != 1)
				num_tokens++;
		}
	}
	return (num_tokens);
}

/**
 * tokenize - break a string into an array of tokens
 * @str: string
 * @delim: delimiter
 * Return: array of strings
 */
char **tokenize(char *str, char *delim)
{
	char *token, **tokens;
	size_t i;
	size_t num_tokens = count_toks(str, delim);

	if (str == NULL || delim == NULL)
		return (NULL);

	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	i = 0;
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, delim);
	}
	tokens[i] = token; /* last token is NULL */
	return (tokens);
}
