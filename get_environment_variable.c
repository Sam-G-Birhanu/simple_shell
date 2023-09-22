#include "shell.h"

/**
 * get_environment_variable - ptr to an environment variable value
 * @var_name: Environment variable name
 *
 * Return: Pointer to the environment variable value
 */
char *get_environment_variable(char *var_name)
{
	int i;

	for (i = 0; __environ[i] != NULL; i++)
	{
		if (_strncmp(__environ[i], var_name, _strleng(var_name)) == 0)
		{
			return (&__environ[i][_strleng(var_name) + 1]);
		}
	}

	return (NULL);
}
