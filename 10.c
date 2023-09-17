#include "shell.h"

/**
 * _myhistory - funcrtion to displays the history list.
 * @infoo: Structure containing potential arguments. Used to main.
 *  Return: Always 0.
 */
int _myhistory(info_t *infoo)
{
	print_list(infoo->history);
	return (0);
}

/**
 * unset_alias - function to sets alias to string.
 * @infoo: takes parameter structure
 * @str: takes the string alias
 * Return: Always 0 , 1 on fail
 */
int unset_alias(info_t *infoo, char *str)
{
	char *b, c;
	int ret;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	c = *b;
	*b = 0;
	ret = delete_node_at_index(&(infoo->alias),
		get_node_index(infoo->alias, node_starts_with(infoo->alias, str, -1)));
	*b = c;
	return (ret);
}

/**
 * set_alias - function to sets alias to string
 * @infoo: takes a parameter struct
 * @str: takes a string alias
 *
 * Return: returns 0 on success, 1 on fail.
 */
int set_alias(info_t *infoo, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(infoo, str));

	unset_alias(infoo, str);
	return (add_node_end(&(infoo->alias), str, 0) == NULL);
}

/**
 * print_alias - fuction to prints an alias string
 * @node: the alias node
 * Return: returns 0 on success, 1 on failure
 */
int print_alias(list_t *node)
{
	char *b = NULL, *a = NULL;

	if (node)
	{
		b = _strchr(node->str, '=');
		for (a = node->str; a <= b; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - function to mimics the alias builtin
 * @infoo: takes a struct containing potential arguments.
 *  Return: Always 0
 */
int _myalias(info_t *infoo)
{
	int s = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (infoo->argc == 1)
	{
		node = infoo->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (s = 1; infoo->argv[s]; s++)
	{
		p = _strchr(infoo->argv[s], '=');
		if (p)
			set_alias(infoo, infoo->argv[s]);
		else
			print_alias(node_starts_with(infoo->alias, infoo->argv[s], '='));
	}

	return (0);
}

