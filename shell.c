#include "shell.h"

/**
 * main - a simple shell program written in C
 *
 * Return: 0 always (but program may exit early)
 */

int main(void)
{
	char *user_input;
	size_t nbytes;
	ssize_t bytes_read;
	char **commands;

	nbytes = 0;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		bytes_read = getline(&user_input, &nbytes, stdin);
		if (bytes_read == -1)
		{
			perror("getline");
			break;
		}

		if (bytes_read == 5)
			exit_check(user_input);

		if (blank_check(user_input) == 1)
			continue;

		commands = parse_input(user_input);
		fork_wait_exec(commands);

		free_commands(commands);
/*
		free(user_input);
*/
	}
	return (0);
}
