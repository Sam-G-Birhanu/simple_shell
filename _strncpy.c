#include "shell.h"

/**
 * _strncpy - Ccpoies a string
 * @destination: String to wich chars are going to be copied
 * @source: String to be copied
 * @num: Num of chars to copy from source
 *
 * Return: Pointer to destination
 */
char *_strncpy(char *destination, char *source, int num)
{
	int count = 0;
	char *start = destination;

	while (*source != '\0' && count < num)
	{
		*(start++) = *(source++);
		count++;
	}

	while (count < num)
	{
		*(start++) = '\0';
		count++;
	}

	return (destination);
}
