#include "shell.h"

/**
 * trim_command - function para timmear string
 * @input: input del usario
 * Return: string que ya esta trimed
 */
char *trim_command(char *input)
{
	char *trimmed;

	trimmed = strtok(input, " \t\n");

	return (trimmed);

}
