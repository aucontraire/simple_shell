#include "shell.h"

void fork_wait_exec(char **commands)
{
	pid_t pid;
	int status;

	status = 0;
	pid = fork();

	if (pid == -1)
	{
		perror("fork failure");
		_exit(1);
	}

	else if (pid == 0)
	{
		if ((execvp(commands[0], commands)) < 0)
		{
			perror(commands[0]);
			_exit(1);
		}
		_exit(0);

	}

	wait(&status);
}

char **parse_input(char *user_input)
{
	char **commands;
	char *token;
	int args, i, length;

	args = 1;
	i = 0;
	while (user_input[i] != '\0' && user_input[i] != '\n')
	{
		if (user_input[i] == ' ')
			args++;
		i++;
	}

	commands = malloc(sizeof(char *) * args + 1);

	token = strtok(user_input, "\n ");
	length = _strlen(token);
	commands[0] = malloc(sizeof(char) * length);
	commands[0] = token;
	token = strtok(NULL, "\n ");

	for (i = 1; i < args; i++)
	{
		length = _strlen(token);
		commands[i] = malloc(sizeof(char) * length);
		commands[i] = token;
		token = strtok(NULL, "\n ");
	}
	commands[i] = NULL;

	return (commands);
}

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
