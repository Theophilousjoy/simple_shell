#include "main.h"

#include "main.h"
/**
 * _eputs - print input string
 * @str: string to print
 *
 * Return: Nothing.
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[w]);
		w++;
	}
}

/**
 * _eputchar - A function that writes character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int x;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(2, buf, w);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buff[x++] = c;
	return (1);
}

/**
 * _putfd - A function that write char c to given fd
 * @c: char to be printed
 * @fd: The filedescriptor to write on
 *
 * Return: return 1 On success
 * On error, -1 , errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int x;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 * _putsfd - A function that print input string
 * @str: string to print.
 * @fd: filedescriptor to write
 *
 * Return: numb of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

