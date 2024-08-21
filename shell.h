#ifndef shell_h

#define shell_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void display_input(char **line, size_t *length);
void fork_func(char *line, char *programa);
int main(int ac, char **av);
size_t _strcspn(const char *s1, const char *s2);
char *trim_command(char *input);

#endif
