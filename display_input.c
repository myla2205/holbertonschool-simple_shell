#include "shell.h"

/**
 * display_input - funcion que demuestra el prompt y
 * lee lo que ponga el usuario
 * @line: pointer a pointer para el input string
 * @length: pointer que recoje el buffer del string
 */

void display_input(char **line, size_t *length)
{
	ssize_t nread;

	if (isatty(STDIN_FILENO))
	{
		printf("#cisfun$ ");
	}

	nread = getline(line, length, stdin);

	if (nread == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\n");
		}

		free(*line);
		exit(0);
	}

	if (nread > 0 && (*line)[nread - 1] == '\n')
	{
		(*line)[nread - 1] = '\0';
	}

	else
	{
		(*line)[_strcspn(*line, "\n")] = '\0';
	}

}
