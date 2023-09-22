#include "shell.h"

/**
 * _strcpy - Copies the string source to destination
 * @destination: destination pointer
 * @source: String source
 *
 * Return: Pointer to destination
 */
char *_strcpy(char *destination, char *source)
{
	char *memory_add;

	memory_add = destination;

	while (*source != '\0')
	{
		*memory_add = *source;
		memory_add++;
		source++;
	}

	*memory_add = '\0';

	return (destination);
}
