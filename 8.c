#include "shell.h"

/**
 * _strcpy - function to copy a string
 * @dest: takes the destin
 * @src: takes the source
 * Return: return pter to destin
 */
char *_strcpy(char *dest, char *src)
{
	int r = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[r])
	{
		dest[r] = src[r];
		r++;
	}
	dest[r] = 0;
	return (dest);
}

/**
 * _strdup - function to duplicate a str
 * @str: takes the str to duplicate
 * Return: returns a pointer
 */
char *_strdup(const char *str)
{
	int leng = 0;
	char *r;

	if (str == NULL)
		return (NULL);
	while (*str++)
		leng++;
	r = malloc(sizeof(char) * (leng + 1));
	if (!r)
		return (NULL);
	for (leng++; leng--;)
		r[leng] = *--str;
	return (r);
}

/**
 * _puts - function to print an input string
 * @str: takes string
 * Return: returns nothing
 */
void _puts(char *str)
{
	int r = 0;

	if (!str)
		return;
	while (str[r] != '\0')
	{
		_putchar(str[r]);
		r++;
	}
}

/**
 * _putchar - function to write the char c to stdout
 * @c: takes the char
 * Return: returns 1.
 */
int _putchar(char c)
{
	static int r;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(1, buf, r);
		r = 0;
	}
	if (c != BUF_FLUSH)
		buf[r++] = c;
	return (1);
}
