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
	char *token;
	char *args[100];
	char path[256];

	token = strtok(line, " \t\r\n");

	while (token != NULL && argc < 99)
	{
		args[argc++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	args[argc] = NULL;

	prepare_command(args, path);

	fork_and_execute(args, programa);

}
