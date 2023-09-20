#include "shell.h"
/**
 * main - a function that executes other programs
 * Return: Exit status
 */
int main()
{
	char *ORIGINAL_PATH;
	ORIGINAL_PATH = getenv("PATH");
	prompt();
	return 0;
}
