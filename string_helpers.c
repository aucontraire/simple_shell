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


/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference of two strings (first minus second) or 0 if equal
 */

int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] != '\0' && s2[index] != '\0'; index++)
	{
		if (s1[index] < s2[index])
			return (s1[index] - s2[index]);

		else if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
	}

	return (0);
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string
 * Return: pointer to newly allocated space in memory
 */

char *_strdup(char *str)
{
	int length, i;
	char *arr;

	length = 0;
	if (str == NULL)
		return (NULL);

	length = _strlen(str);

	arr = malloc((length + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		arr[i] = str[i];

	arr[i] = '\0';

	return (arr);
}

/**
 * _atoi - turns a string into an integer
 * @s: string
 *
 * Return: integer
 */

int _atoi(char *s)
{
	unsigned int index, neg_counter, num;

	index = 0;
	neg_counter = 0;

	while (!(s[index] >= '0' && s[index] <= '9') && s[index] != '\0')
	{
		if (s[index] == '-')
			neg_counter++;

		index++;
	}

	num = 0;

	while (s[index] >= '0' && s[index] <= '9')
	{
		num = (s[index] - '0') + (num * 10);
		index++;
	}

	if (neg_counter % 2 != 0)
		num = -num;

	return (num);
}

/**
 * print_number - print an integer
 * @n: integer to print
 */

void print_number(int n)
{
	int digit, sum, last;
	int divis = 1000000000;
	unsigned int num;

	num = n;
	sum = 0;

	while (divis > 1)
	{
		digit = (num / divis) % 10;
		sum += digit;
		if (sum != 0)
			_putchar(digit + '0');
		divis = divis / 10;
	}

	last = num % 10;
	_putchar(last + '0');
}

/**
* _putchar - prints a single character to stdout
* @c: The character to print
*
* Return: 1 if successful, -1 otherwise
*/
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
