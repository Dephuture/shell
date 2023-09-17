#include "shell.h"

/**
 **_strncpy -function to  copy a string
 *@dest: takes the destination string to be copied
 *@src: takes the source string
 *@n: takes the amount of characters to be copied
 *Return: takes the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, r;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		r = a;
		while (r < n)
		{
			dest[r] = '\0';
			r++;
		}
	}
	return (s);
}

/**
 **_strncat - function to concatenate two strings
 *@dest: takes the first string
 *@src: takes the second string
 *@n: takes the amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - function to locate a char in a string
 *@s: takes string to be parsed
 *@c: takes the char to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
