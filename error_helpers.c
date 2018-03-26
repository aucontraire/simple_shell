#include "shell.h"

/**
 *
 *
 */

void command_error(__attribute__((unused)) char* NAME, char *command)
{
	write(STDOUT_FILENO, command, _strlen(command));
	write(STDOUT_FILENO, ": command not found\n", 20);
}

/**
 *
 *
 */
