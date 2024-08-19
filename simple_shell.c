#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/**
 * main - function para simple shell
 * Return: 0 es exito
 */

int main(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t leido;
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		leido = getline(&line, &length, stdin);
		if (leido == -1)
		{
			printf("\n");
			break;
		}
		if (line[leido - 1] == '\n')
		{
			line[leido - 1] = '\0';
		}
		if (strlen(line) == 0)
		{
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			char *args[] = {line, NULL};

			execve(args[0], args, environ);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
