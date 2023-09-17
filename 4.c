#include "shell.h"

/**
 * input_buf - function to buffers chained commands
 * @infoo: takes a parameter struct
 * @buf: takes address of buffer
 * @len: takes an address of len var
 * Return: bytes
 */
ssize_t input_buf(info_t *infoo, char **buf, size_t *len)
{
	ssize_t i = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		i = getline(buf, &len_p, stdin);
#else
		i = _getline(infoo, buf, &len_p);
#endif
		if (i > 0)
		{
			if ((*buf)[i - 1] == '\n')
			{
				(*buf)[i - 1] = '\0';
				i--;
			}
			infoo->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(infoo, *buf, infoo->histcount++);
			{
				*len = i;
				infoo->cmd_buf = buf;
			}
		}
	}
	return (i);
}

/**
 * get_input - function to get a line minus the newline
 * @infoo: takes a parameter struct
 * Return: bytes
 */
ssize_t get_input(info_t *infoo)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(infoo->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(infoo, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(infoo, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(infoo, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			infoo->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * read_buf - function to reads a buffer
 * @infoo: takes a parameter struct
 * @buf: takes a buffer
 * @i: takes the size
 * Return: returns sttring
 */
ssize_t read_buf(info_t *infoo, char *buf, size_t *i)
{
	ssize_t m = 0;

	if (*i)
		return (0);
	m = read(infoo->readfd, buf, READ_BUF_SIZE);
	if (m >= 0)
		*i = m;
	return (m);
}

/**
 * _getline - function to get the next line of input from STDIN
 * @infoo: takes a parameter struct
 * @ptr: takes an address of pointer to buffer, preallocated or NULL
 * @length: takes the size of preallocated ptr buffer if not NULL
 * Return: returns s
 */
int _getline(info_t *infoo, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t a, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (a == len)
		a = len = 0;

	r = read_buf(infoo, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + a, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + a, k - a);
	else
		_strncpy(new_p, buf + a, k - a + 1);

	s += k - a;
	a = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler -function to blocks ctrl-C
 * @sig_num: yakes the signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
