#include "shell.h"

/**
 * _puts - Prints a string to standard output
 * @str: String to be printed
 *
 * Return: No of chars printed
*/
int _puts(char *strng)
{
	int leng = _strleng(strng);

	write(STDOUT_FILENO, strng, leng);

	return (leng);
}
