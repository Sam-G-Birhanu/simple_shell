#include "shell.h"

/**
 * print_environment - Prints the environment variables to stdout
*/
void print_environment(void)
{
	int i;
	char **env = __environ;

	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, env[i], _strleng(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	set_custom_exit_code(0);
}
