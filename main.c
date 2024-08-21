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

	(void)ac;

	while (1)
	{
		display_input(&line, &length);

		if (strcmp(line, "exit") == 0)
		{
			break;
		}

		if (strlen(line) > 0)
		{
			fork_func(line, av[0]);
		}

		free(line);
		line = NULL;
	}

	free(line);
	return (0);
}
