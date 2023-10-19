#include "main.h"

/**
 * _error_atoi - A function that convert strg to int
 * @s: strng to convert.
 * Rtn: no numb return 0 , converted num otherwise
 *       return -1 on error
 */

int _error_atoi(char *s)
{
	int x = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (x = 0;  s[i] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			result *= 10;
			result += (s[x] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}




