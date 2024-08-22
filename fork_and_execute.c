#include "shell.h"

/**
 * fork_and_execute - funcion que como tal ejecuta
 * comandos a traves de execve en
 * child process
 * @args: arreglo de string con comandos
 * @programa: nombre de programa
 */

void fork_and_execute(char *args[], char *programa)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(programa);
		}

		exit(EXIT_FAILURE);
	}

	else if (pid < 0)
	{
		perror("fork");
	}

	else
	{
		wait(NULL);
	}
}
