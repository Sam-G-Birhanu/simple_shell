#include "shell.h"
/**
 * main - a function that executes other programs
 * Return: Exit status
 */
/** char *ORIGINAL_PATH = NULL; **/
int main()
{
	const char *ORIGINAL_PATH = getenv("PATH");
	printf("%s original path" , ORIGINAL_PATH);
	prompt(ORIGINAL_PATH);
	return 0;
}

