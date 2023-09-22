#include "shell.h"

/**
 * env - Prints the environment variables to stdout
*/
void env(void)
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
/**
 * set_env - Sets or adds an environment variable
 * @name: Name for the new env variable
 * @value: Value for the new env variable
 *
 * Return: 1 on success, -1 on error
 */
int set_env(char *name, char *value)
{
	int env_index, new_var_len;

	if (validate_env_name(name) == -1)
		return (-1);

	env_index = get_env_var_index(name);
	if (env_index == -1)
	{/* var doen't exist, SO CREATE IT */
		int env_count = 0;
		int old_size, new_size;

		while (__environ[env_count] != NULL)
			env_count++;

		old_size = sizeof(char *) * (env_count);
		new_size = sizeof(char *) * (env_count + 2);
		__environ = fun_reallocate(__environ, old_size, new_size);
		if (__environ == NULL)
			dispatchError("Error while fun_reallocateating memory for new env var");

		/* The new value will be stored at index env_count */
		env_index = env_count;
		/* last value For the new env var needs to be NULL */
		__environ[env_count + 1] = NULL;
	}
	else
	{
		/* var exists, so overwrite it's value */
		free(__environ[env_index]);
	}

	new_var_len = _strleng(name) + _strleng(value) + 2;
	/* store the env var either if it exists or it needs to be overwritten */
	__environ[env_index] = alloc_mem(sizeof(char) * new_var_len);
	_strcpy(__environ[env_index], name);
	str_cat(__environ[env_index], "=");
	str_cat(__environ[env_index], value);

	set_custom_exit_code(0);
	return (1);
}
/**
 * unset_env - Removes an evironment variable
 * @name: Name for the new env variable
 *
 * Return: 1 on success, -1 on error
 */
int unset_env(char *name)
{
	int env_index, i;

	env_index = get_env_var_index(name);
	if (env_index >= 0)
	{/* var exists, We can unset it */
		free(__environ[env_index]);

		for (i = env_index; __environ[i] != NULL; i++)
			__environ[i] = __environ[i + 1];

		set_custom_exit_code(0);
		return (1);
	}

	/* Var doesn't exist, we can print error or do nothing */
	set_custom_exit_code(0); /* Indicates that no error ocurred */

	return (1);
}

/**
 * change_directory - Changes the current directory of the process
 * @path: Path to wich change the working directory
 *
 * Return: 1 on success, -1 on error
*/
int change_directory(char *path)
{
	char buff[1024];
	char *oldpwd;
	char *_path = path;

	if (_strcmp(path, "-") == 0)
		path = get_environment_variable("OLDPWD");

	if (path == NULL)
	{
		printError("cd: OLDPWD not set", "");
		return (-1);
	}
	/* Needed to avoid reading on freed memory */
	path = dup_str(path);
	/* store this dir in case of update */
	oldpwd = getcwd(buff, 1024);
	if (oldpwd == NULL)
	{
		free(path);
		printError("cd: couldn't get current dir", "");
		return (-1);
	}
	/* Try to change the current dir */
	if (chdir(path) == -1)
	{
		free(path);
		printError("cd: can't change cd to ", _path);
		set_custom_exit_code(1);
		return (-1);
	}
	/* Update env variables */
	set_env("OLDPWD", oldpwd);
	set_env("PWD", path);
	free(path);
	set_custom_exit_code(0);
	return (1);
}

/**
 * _alias - Sets an alias command
 * @commands: List of commands
 *
 * Return: -1 on error, 0 otherwise
*/
int _alias(char **commands)
{
	int status = 0;
	list_t *curr;
	list_t *out_head = NULL;
	list_t **alias_addrs = get_alias_head();

	if (commands[1] == NULL)
	{ 
		for (curr = *alias_addrs; curr != NULL; curr = curr->next)
		{
			_puts(curr->str);
			_puts("\n");
		}
		set_custom_exit_code(0);
		return (1);
	}
	/* List aliases and sets the aliases that have the form name=value */
	status = handle_alias_args(commands, &out_head);
	for (curr = out_head; curr != NULL; curr = curr->next)
	{
		_puts(curr->str);
		_puts("\n");
	}
	free_linked_list(out_head);
	return (status);
}
