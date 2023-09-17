#include "shell.h"

/**
 * list_len - function to determines length of linked lst.
 * @a: takes a ptr to frt node.
 * Return: returns the size of lst.
 */
size_t list_len(const list_t *a)
{
	size_t r = 0;

	while (a)
	{
		a = a->next;
		r++;
	}
	return (r);
}

/**
 * list_to_strings - function that rtns an array of strings.
 * @head: takes a ptr to 1st node
 * Return: returns an array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t r = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !r)
		return (NULL);
	strs = malloc(sizeof(char *) * (r + 1));
	if (!strs)
		return (NULL);
	for (r = 0; node; node = node->next, r++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < r; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[r] = str;
	}
	strs[r] = NULL;
	return (strs);
}


/**
 * print_list - function to print all elements of  linked list
 * @k: takes a pter to 1st node
 * Return: returns the size of list
 */
size_t print_list(const list_t *k)
{
	size_t r = 0;

	while (k)
	{
		_puts(convert_number(k->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(k->str ? k->str : "(nil)");
		_puts("\n");
		k = k->next;
		r++;
	}
	return (r);
}

/**
 * node_starts_with - function to returns node string with
 * @node: takes a pter to list head
 * @prefix: takes a string
 * @c: checks the next char after prefix
 * Return: returns the match node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((c == -1) || (*q == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - function to get the index of a node
 * @head: takes a pter to lst hd
 * @node: takes a pointer to the node
 * Return: returns an index of node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t r = 0;

	while (head)
	{
		if (head == node)
			return (r);
		head = head->next;
		r++;
	}
	return (-1);
}
