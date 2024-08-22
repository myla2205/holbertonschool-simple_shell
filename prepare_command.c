#include "shell.h"

/**
 * prepare_command - funcion para asegurar que apunta al ejecutable correcto
 * @args: arreglo de strings donde args[0] es el comando
 * @path: buffer para aguantar path completo
 */

void prepare_command(char *args[], char *path)
{
	if (strchr(args[0], '/') == NULL)
	{
		sprintf(path, "/bin/%s", args[0]);
		args[0] = path;
	}
}
