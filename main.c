#include "shell.h"

/**
 * main - function imrpime prompt
 * @ac: argument count
 * @av: pointer to pointer argument vector
 * Return: 0 es exito
 */

int main(int ac, char **av)
{
	char *line = NULL;
	size_t length = 0;
	char *trimmed_line;

	(void)ac;

	while (1)
	{
		display_input(&line, &length);
		trimmed_line = trim_command(line);

		if (strcmp(trimmed_line, "exit") == 0)
		{
			break;
		}

		if (strlen(trimmed_line) > 0)
		{
			fork_func(trimmed_line, av[0]);
		}

		free(line);
		line = NULL;
	}

	free(line);
	return (0);
}
