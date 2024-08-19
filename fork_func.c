#include "shell.h"

/**
 * fork - function que usa fork para fork un nuevo process
 * y ejecuta el commando entrado por usuario
 * @line: pointer que recibe el input
 */

void fork_func(char *line)
{
	/**
	 * args es un array de strings, donde el primer elemento
	 * line es el commando, y el segundo es NULL, para facilitar execve
	 * pid esta guardando el resultado de fork, si es -1, dio error
	 * si es 0 es el child
	 */
	char *args[] = {line, NULL};
	pid_t pid = fork();

	/**
	 * if statement para validar si estamos en proceso hijo
	 * args[0] guarda el comando a ejecutarse
	 * args es un array of strings que contiene los argumentos a ser
	 * pasados al nuevo programa, segundo argumento es NULL para
	 * que execve sepa que es el final de los argumentos
	 * EXIT_FAILURe es un macro incluido en stdlib.h que retorna 1
	 */
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("./shell");
		exit(EXIT_FAILURE);
	}

	else if (pid > 0)
	{
		wait(NULL);
	}

	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
