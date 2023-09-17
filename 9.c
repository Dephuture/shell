#include "shell.h"

/**
 * is_chain - function to test if current char in buffer
 * @infoo: takes the parameter structure.
 * @buf: takes the char
 * @p: takes an address of current position in buffer.
 * Return: returns 1.
 */
int is_chain(info_t *infoo, char *buf, size_t *p)
{
	size_t i = *p;

	if (buf[i] == '|' && buf[i + 1] == '|')
	{
		buf[i] = 0;
		i++;
		infoo->cmd_buf_type = CMD_OR;
	}
	else if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;
		i++;
		infoo->cmd_buf_type = CMD_AND;
	}
	else if (buf[i] == ';')
	{
		buf[i] = 0;
		infoo->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = i;
	return (1);
}

/**
 * check_chain - function to check continue chain based on last status.
 * @infoo: takes parameter struct
 * @buf: takes char buffer
 * @p: takes an address of current position in buffer
 * @i: takes the starting position in buffer
 * @len: takes length of buf
 * Return: returns Void.
 */
void check_chain(info_t *infoo, char *buf, size_t *p, size_t i, size_t len)
{
	size_t a = *p;

	if (infoo->cmd_buf_type == CMD_AND)
	{
		if (infoo->status)
		{
			buf[i] = 0;
			a = len;
		}
	}
	if (infoo->cmd_buf_type == CMD_OR)
	{
		if (!infoo->status)
		{
			buf[i] = 0;
			a = len;
		}
	}

	*p = a;
}

/**
 * replace_alias - function to replace an aliases
 * @infoo: takes the para struct
 * Return: returns 1.
 */
int replace_alias(info_t *infoo)
{
	int j;
	list_t *node;
	char *b;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(infoo->alias, infoo->argv[0], '=');
		if (!node)
			return (0);
		free(infoo->argv[0]);
		b = _strchr(node->str, '=');
		if (!b)
			return (0);
		b = _strdup(b + 1);
		if (!b)
			return (0);
		infoo->argv[0] = b;
	}
	return (1);
}

/**
 * replace_vars - function to replace vars
 * @infoo: the para struct
 * Return: returns 1
 */
int replace_vars(info_t *infoo)
{
	int j = 0;
	list_t *node;

	for (j = 0; infoo->argv[j]; j++)
	{
		if (infoo->argv[j][0] != '$' || !infoo->argv[j][1])
			continue;

		if (!_strcmp(infoo->argv[j], "$?"))
		{
			replace_string(&(infoo->argv[j]),
					_strdup(convert_number(infoo->status, 10, 0)));
			continue;
		}
		if (!_strcmp(infoo->argv[j], "$$"))
		{
			replace_string(&(infoo->argv[j]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(infoo->env, &infoo->argv[j][1], '=');
		if (node)
		{
			replace_string(&(infoo->argv[j]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&infoo->argv[j], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - function to replace string
 * @old: takes address of old string
 * @new: takes the new string
 * Return: returns 1 if replaced
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
