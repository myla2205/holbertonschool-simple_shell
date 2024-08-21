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
	int i;
	char *token = strtok(line, " \t\r\n");
	char *args[100];
	pid_t pid;

	for (i = 0; i < 100; i++)
	{
		args[i] = NULL;
	}

	while (token != NULL && argc < 99)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " \t\r\n");
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
