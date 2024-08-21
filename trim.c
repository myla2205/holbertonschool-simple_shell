#include "shell.h"

/**
 * trim_command - funcion que recibe un string y elimina whitespaces
 * sea spaces, tabs or newlines.
 * @input: pointer que es el string que puso usuario
 * Return: string que ya esta trimed
 */
char *trim_command(char *input)
{
	char *start, *end;

	start = input;

	while (*start && strchr(" \t\n", *start))
	{
		start++;
	}

	end = start + strlen(start) - 1;

	while (end > start && strchr(" \t\n", *end))
	{
		end--;
	}

	*(end + 1) = '\0';

	return (start);

}
