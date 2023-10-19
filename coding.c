#include "main.h"

/**
 * main - Entry point
 * @ac: arg cnt
 * @av: arg vec
 *
 * Return: on success 0, 1 on error
 */


int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fds = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fds)
			: "r" (fds));

	if (ac == 2)
	{
		fds = open(av[1], O_RDONLY);
		if (fds == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fds;
	}
	envn_list_pop(info);
	rd_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

