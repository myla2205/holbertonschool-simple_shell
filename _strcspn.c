#include "shell.h"

/**
 * _strcspn - function para reemplazar strcspn
 * @s1: pointer a string 1
 * @s2: pointer a tring 2
 * Return: ret
 */

size_t _strcspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (s1)
	{
		if (strchr(s2, *s1))
		{
			return (ret);
		}
		else
		{
			s1++, ret++;
		}
	}
	return (ret);
}
