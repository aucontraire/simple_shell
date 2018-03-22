#include "shell.h"

/**
 * get_path_count - counts number of directories in PATH
 * @path: PATH string
 *
 * Return: number of directories
 */

int get_path_count(char *path)
{
	int i, count;

	i = 0;
	count = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '=' || path[i] == ':')
			count++;
		i++;
	}

	return (count);
}

/**
 * get_path_array - creates an array of PATH directories
 * @env: user environment
 *
 * Return: array of strings
 */

char **get_path_array(char **env)
{
	unsigned int i, j;
	int compare, path_count, length;
	char *token;
	char **path_array;

	compare = 0;
	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		compare = strncmp(env[i], "PATH", 4);
		if (compare == 0)
		{

			path_count = get_path_count(env[i]);
			path_array = malloc(sizeof(char *) * path_count + 1);
			if (path_array == NULL)
				return (NULL);

			token = strtok(env[i], "=:");
			while (j < path_count)
			{
				if (token[0] != 'P')
				{
					length = _strlen(token);
					path_array[j] = malloc(sizeof(char) * length + 1);
					/* check if malloc fails */
					path_array[j] = token;
					j++;
				}
				token = strtok(NULL, "=:");
			}
		}
		i++;
	}

	return (path_array);
}
