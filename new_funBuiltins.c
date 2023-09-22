#include "shell.h"

/**
 * get_env_var_index - Check if an environment variable exists and returns the index
 * @env_name: Name to be searched
 *
 * Return: Index of the environment variable, -1 on error
*/
int get_env_var_index(char *env_name)
{
	int i;
	int len = _strleng(env_name);

	for (i = 0; __environ[i] != NULL; i++)
		if (strncmp(__environ[i], env_name, len) == 0)
			return (i);

	return (-1);
}

/**
 * validate_env_var_name - Validates an environment variable name
 * @env_name: String to be validated
 *
 * Return: 0 on success, -1 on error
*/
int validate_env_var_name(char *env_name)
{
	if (env_name == NULL)
	{
		printError("setenv: Needs 2 args", "");
		return (-1);
	}

	if (!is_valid_env_var_name(env_name))
	{
		print_builtin_error("setenv: Invalid name ", env_name);
		return (-1);
	}

	return (0);
}

/**
 * is_valid_env_var_name - Checks if the environment variable name is valid
 * @env_name: String to be checked
 *
 * Return: 1 if valid, 0 otherwise
*/
int is_valid_env_var_name(char *env_name)
{
	int i;
	/* Verify that name is a valid env_var name (without "=") */
	for (i = 0; env_name[i] != '\0'; i++)
		if (env_name[i] == '=')
			return (0);

	return (1);
}
