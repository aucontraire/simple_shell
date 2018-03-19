 #include "shell.h"

void get_command(char *user_input)
{
	int compare, status, i;
	pid_t child_pid;
	char *argv[3];

	status = 1;
	argv[0] = strtok(user_input, " \n");;

	for (i = 1; argv[i] != NULL; i++)
	{
		argv[i] = strtok(NULL, " \n");
	}
	argv[i] = '\0';

	compare = strncmp("exit", user_input, 4);
	if (compare == 0)
	{
		printf("Exiting...\n");
		free(user_input);
		exit(0);
	}
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execvp(*argv, argv) != 0)
				perror("./hsh");
		}
		else
			wait(&status);
	}
}

/**
 * main - simple shell
 * Return: 0 (Always)
 */

int main(void)
{
	int bytes_read;
	char *user_input;
	size_t nbytes;

	nbytes = 1024;
	while (nbytes != 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		user_input = malloc(sizeof(char) * nbytes);
		if (user_input == NULL)
		{
			perror("malloc\n");
			break;
		}
		bytes_read = getline(&user_input, &nbytes, stdin);
		if (bytes_read == -1)
		{
			perror("getline\n");
			free(user_input);
			break;
		}
		get_command(user_input);
		free(user_input);
	}

	return (0);
}
