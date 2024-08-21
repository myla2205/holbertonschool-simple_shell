#include "shell.h"

/**
 * fork_func - function que usa fork para fork un nuevo process
 * y ejecuta el commando entrado por usuario
 * @line: pointer que recibe el input
 * @programa: pointer que nombre de programa ejecutable
 */

void fork_func(char *line, char *programa)
{
	int argc = 0;
	char *token = strtok(line, " ");
	char *args[100];
	pid_t pid;

	while (token != NULL && argc < 100)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " ");
	}
	args[argc] = NULL;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(programa);
		}
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
