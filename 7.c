#include "shell.h"

/**
 * _memset - function to fill memory with a const byte
 * @s: takes the pnter to the memory
 * @b: takes the byte to fill *s
 * @n: takes the amount of bytes to be filled
 * Return: returns a pnter to the memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		s[j] = b;
	return (s);
}

/**
 * ffree - function to free a string
 * @pp: takes a string of strings
 */
void ffree(char **pp)
{
	char **b = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(b);
}

/**
 * _realloc - function to reallocate a block of mry.
 * @ptr: takes a pnter to previous block.
 * @old_size: takes a byte sz of previous block.
 * @new_size: takes a byte sz of new block.
 * Return: returns a pointer to the nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	q = malloc(new_size);
	if (!q)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		q[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (q);
}
