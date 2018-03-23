#include "shell.h"

/**
 * parse_input - parsers user_input to create an array of strings
 * @user_input: string to tokenize
 * @path_array: array of directories in PATH
 *
 * Return: an array of arguments
 */

char **parse_input(char *user_input, char **path_array)
{
	char **commands;
	char *token, *dir_path;
	int args, i;

	args = 1;
	i = 0;
	while (user_input[i] != '\0' && user_input[i] != '\n')
	{
		if (user_input[i] == ' ' && user_input[i + 1] != ' '
		    && user_input[i + 1] != '\n')
			args++;
		i++;
	}

	commands = malloc(sizeof(char *) * args);
	token = strtok(user_input, "\n ");

	if (path_check(token) == -1)
	{
		dir_path = find_path(path_array, token);
		if (dir_path != NULL)
			token = dir_path;
	}

/*	length = _strlen(token);
	commands[0] = malloc(sizeof(char) * (length + 1)); */
	commands[0] = _strdup(token);
/*	commands[0][length] = '\0'; */

	for (i = 1; i < args; i++)
	{
		token = strtok(NULL, "\n ");
/*		length = _strlen(token);
		commands[i] = malloc(sizeof(char) * (length + 1)); */
		commands[i] = _strdup(token);
/*		commands[i][length] = '\0'; */
	}

	commands[args] = NULL;

	return (commands);
}
