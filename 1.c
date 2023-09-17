#include "shell.h"

/**
 * interactive - function to  return true if shell is interactive mode
 * @infoo: takes struct address
 *
 * Return: 1 if interactive mode
 */
int interactive(info_t *infoo)
{
	return (isatty(STDIN_FILENO) && infoo->readfd <= 2);
}

/**
 * is_delim - function to checks if character is a delimeter
 * @c: takes the char
 * @deliim: takes delimeter string
 * Return: returns 1 true, 0 false
 */
int is_delim(char c, char *deliim)
{
	while (*deliim)
		if (*deliim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - functio to checks for alphabetic
 * @c: TakestThe char to input
 * Return: 1 alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - fuction to converts a string to an int
 * @s: takes the string to  convert
 * Return: 0 if no numbers in string
 */

int _atoi(char *s)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0; s[a] != '\0' && flag != 2; a++)
	{
		if (s[a] == '-')
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
