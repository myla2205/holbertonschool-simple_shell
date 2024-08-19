#include "shell.h"

/**
 * display_input - funcion que demuestra el prompt y
 * lee lo que ponga el usuario
 * @line: pointer a pointer para el input string
 * @length: pointer que recoje el buffer del string
 */

void display_input(char **line, size_t *length)
{
	if(isatty(STDIN_FILENO))
	{
		printf("#cisfun$ ");
	}

	/*
	 * getline recoge el input de usuario y lo guarde en line
	 * y recoge el largo del input y lo guarde en length
	 * si da error, -1, imprime newline y exit
	 * isatty es una function para chequear si el input viene del terminal
	 */

	if (getline(line, length, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\n");
		}

		exit(0);
	}

	/**
	 * usamos string comparison para calcular el largo largo del string
	 * hasta llegar el delimitator, que es el new line
	 * y lo remplaza con un null terminator
	 */

	(*line)[strcspn(*line, "\n")] = '\0';

}
