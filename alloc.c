#include "main.h"
/**
 * _memset - Occupy mem with const byte
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int w;

	for (w = 0; w < n; w++)
		s[w] = b;
	return (s);
}

/**
 * strn of strn
 */
void ffree(char **pp)
{
        char **a =pp;

        if (!pp)
                return;
        while (*pp)
                free(*pp++);
        free(a);
}

/**
 * _alloc - allocting new block of memory
 * @pointer: pointer to previous blocks
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
