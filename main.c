#include "shell.h"

/**
 * main - function imrpime prompt
 * Return: 0 es exito
 */

int main(void)
{
	char *line = NULL;
	size_t length = 0;

	while (1)
	{
		display_input(&line, &length);

		if (strcmp(line, "exit") == 0)
		{
			break;
		}

		if (strlen(line) > 0)
		{
			fork_func(line);
		}
	}

	free(line);
	return (0);
}
