#include "shell.h"

/**
 * bfree - function to free a pter
 * @ptr: takes the address of the pointer to free
 * Return: returns 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
