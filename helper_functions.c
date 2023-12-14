#include "monty.h"

/**
 * tokenize_line - parses a line into tokens.
 * @line: the line to be tokenized.
 * @num_tokens: keeping count of the number of tokens.
 * Return: address of teh new struct token_s to hold each token.
 */
Token *tokenize_line(char *line, int *num_tokens)
{
	Token *tokens;
	char *args;

	tokens = malloc(MAX_TOKEN * sizeof(Token));
	if (tokens == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*num_tokens = 0;
	args = strtok(line, " \t\n");
	while (args != NULL)
	{
		tokens[*num_tokens].value = strdup(args);
		if (tokens[*num_tokens].value == NULL)
		{
			dprintf(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		*num_tokens += 1;
		args = strtok(NULL, " \t\n");
	}
	return (tokens);
}

/**
 * free_tokens - frees the memory allocated for tokens.
 * @tokens: the tokens to be freed.
 * @num_tokens: the number of tokens in the array.
 */
void free_tokens(Token *tokens, int num_tokens)
{
	int i;

	for (i = 0; i < num_tokens; i++)
	{
		free(tokens[i].value);
	}
	free(tokens);
}
