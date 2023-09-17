#include "shell.h"

/**
 * _myenv -function to prints the current environment
 * @infoo: takes a struct containing potential args.
 * Return: returns 0.
 */
int _myenv(info_t *infoo)
{
	print_list_str(infoo->env);
	return (0);
}

/**
 * _getenv - function to get the value of an environment variable
 * @infoo: takes Struct containing potential arguments.
 * @name: takes name evn
 * Return: the value of fu
 */
char *_getenv(info_t *infoo, const char *name)
{
	list_t *node = infoo->env;
	char *b;

	while (node)
	{
		b = starts_with(node->str, name);
		if (b && *b)
			return (b);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - function to initialize a new environment variable.
 * @infoo: takes a structure containing potential arguments.
 *  Return: Always 0
 */
int _mysetenv(info_t *infoo)
{
	if (infoo->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(infoo, infoo->argv[1], infoo->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - function to remove an environment variable
 * @infoo: takes a structure containing potential arg.
 * Return: Always 0
 */
int _myunsetenv(info_t *infoo)
{
	int a;

	if (infoo->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (a = 1; a <= infoo->argc; a++)
		_unsetenv(infoo, infoo->argv[a]);

	return (0);
}

/**
 * populate_env_list - function to populate env list
 * @infoo: Structure containing potential args.
 * Return: Always returns 0
 */
int populate_env_list(info_t *infoo)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	infoo->env = node;
	return (0);
}
