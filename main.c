#include "monty.h"

FILE *check_file(int ac, char *av[])
{
	FILE *file;

	if (ac == 1 || ac > 2)
	{
		dprintf(2, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file av[1]\n");
		exit(EXIT_FAILURE);
	}
	return (file);
}

int main(int ac, char *av[])
{
	int i;
	FILE *file;
	char line[MAX_TOKEN], *token, *args[2] = {NULL, NULL};
	
	file = check_file(ac, av);
	while (fgets(line, sizeof(line), file))
	{
		i = 0;
		args[i] = strtok(line, " \t\n");
		while (args[i])
		{
			i++;
			args[i] = strtok(NULL, " \t\n");
		}
	}

	return (0);
}
