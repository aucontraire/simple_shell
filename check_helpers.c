#include "shell.h"

/**
 * exit_check - checks if user input is "exit" and, if so, exits the shell
 * @user_input: string to compare to "exit"
 */

void exit_check(char *user_input)
{
	int i;
	char *check = "exit";

	for (i = 0; check[i] != '\0'; i++)
	{
		if (check[i] != user_input[i])
			return;
	}

	exit(0);
}

/**
 * blank_check - checks if user input is just a return
 * @user_input: string to compare to "\n"
 *
 * Return: 1 if user_input is equal to '\n', 0 otherwise
 */

int blank_check(char *user_input)
{
	if (user_input[0] == '\n')
		return (1);

	return (0);
}
