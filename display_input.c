#include "shell.h"

/**
 * display_input - funcion que demuestra el prompt y
 * lee lo que ponga el usuario
 * @line: pointer a pointer para el input string
 * @length: pointer que recoje el buffer del string
 */

void display_input(char **line, size_t *length)
{
	if (isatty(STDIN_FILENO))
	{
		printf("#cisfun$ ");
	}

	if (getline(line, length, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\n");
		}

		exit(0);
	}

	(*line)[_strcspn(*line, "\n")] = '\0';

}
