#include "shell.h"

/**
 * _strlen - returns the length of a null-terminated string
 * @str: string
 *
 * Return: length of string, minus null terminator
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
