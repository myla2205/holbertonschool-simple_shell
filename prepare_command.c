#include "shell.h"

/**
 * prepare_command - funcion
 * @args: args
 * @path: path
 */

void prepare_command(char *args[], char *path)
{
	if (strchr(args[0], '/') == NULL)
	{
		sprintf(path, "/bin/%s", args[0]);
		args[0] = path;
	}
}
