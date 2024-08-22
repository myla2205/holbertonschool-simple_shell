# Simple Shell

This project implements a simple shell in C that can execute basic commands by forking processes. The shell reads user input, processes commands, and executes them in a new process. The shell also supports some basic command-line parsing and command trimming.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Functions](#functions)
- [Compilation](#compilation)
- [Example](#example)
- [License](#license)

## Overview

The simple shell program is a command-line interpreter that reads user input, parses the input into commands and arguments, and executes those commands. The shell continues running until the user types the command `exit`.

## Features

- **Prompt Display**: The shell displays a custom prompt (`#cisfun$ `) when waiting for user input.
- **Command Parsing**: The shell supports commands with arguments, trimming of excess whitespace, and handles input using standard C functions.
- **Process Creation**: Commands are executed in a separate process using `fork()` and `execve()`.
- **Graceful Exit**: The shell exits cleanly when the `exit` command is issued.

## Usage

To use the shell, simply run the compiled program. It will display a prompt where you can enter commands. The shell will execute the command and display the prompt again until you exit.

### Commands

- **exit**: Exits the shell.
- **Other commands**: Any command that can be found in `/bin/`, such as `ls`, `echo`, `pwd`, etc.

### Input Handling

- The shell trims leading and trailing whitespace from commands.
- If the command does not include a path and contains no `/`, the shell assumes the command is located in `/bin/`.

## Functions

### `main(int ac, char **av)`
The entry point of the program. It initializes necessary variables, enters an infinite loop to display the prompt, reads input, processes the command, and executes it. The loop continues until the user types `exit`.

### `void display_input(char **line, size_t *length)`
Displays the shell prompt, reads the input from the user, and handles the case when no input is provided. It also trims the newline character from the end of the input string.

### `char *trim_command(char *input)`
Trims leading and trailing whitespace from the input command. It returns a pointer to the trimmed string.

### `void fork_func(char *line, char **programa)`
Parses the input command into arguments, prepares the command for execution, and forks a new process to execute the command.

### `void prepare_command(char *args[], char *path)`
Prepares the command by checking if it includes a path. If not, it prepends `/bin/` to the command, assuming the command is in the `/bin` directory.

### `void fork_and_execute(char *args[], char *programa)`
Handles the creation of a new process using `fork()`. The child process executes the command using `execve()`. The parent process waits for the child to finish before displaying the prompt again.

## Compilation

To compile the shell, use the following command:

```sh
gcc -o simple_shell shell.c -Wall -Werror -Wextra -pedantic

