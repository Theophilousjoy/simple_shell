#include "main.h"

#include "main.h"

/**
 * _my_env - A function that print current environ
 * @info: Structure containing potential arguments. Used for maintaining
 *          constant function prototype.
 * Return: Always 0 Success
 */
int _grpenv(info_t *info)
{
	print_list_of_strns(info->env);
	return (0);
}

/**
 * _getenv - A function that get value of  environ var
 * @info: Structure containing potential arguments.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _grpsetenv - A function that Initialize new environ var,
 *             or modify the existing
 * @info: Structure containing potential arguments. Used for maintain
 *        constant function prototype.
 *  Return: Always 0 Success
 */
int _grpsetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_set_environ(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _grpunsetenv - A function that Remove an environ var
 * @info: Structure containing potential arguments. Used for maintaining
 *        constant function prototype.
 * Return: Always 0 Success
 */
int _grpunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_un_environ(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - A func dat to populate env linked list
 * @info: Structuring contain potential arguments. Used for maintaining
 *          constant function prototype.
 * Return: Always 0 Success
 */
int envn_list_pop(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		sum_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

