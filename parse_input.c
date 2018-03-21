#include "shell.h"

/**
 * parse_input - parsers user_input to create an array of strings
 * @user_input: string to tokenize
 *
 * Return: an array of arguments
 */

char **parse_input(char *user_input)
{
	char **commands;
	char *token;
	int args, i, length;

	args = 1;
	i = 0;
	while (user_input[i] != '\0' && user_input[i] != '\n')
	{
		if (user_input[i] == ' ' && user_input[i + 1] != ' ' && user_input[i + 1] != '\n')
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
