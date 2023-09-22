#include "shell.h"

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

	if (strcmp(path, "-") == 0)
		path = get_environment_variable("OLDPWD");

	if (path == NULL)
	{
		print_builtin_error("cd: OLDPWD not set", "");
		return (-1);
	}
	/* Needed to avoid reading on freed memory */
	path = duplicate_string(path);
	/* store this dir in case of update */
	oldpwd = getcwd(buff, 1024);
	if (oldpwd == NULL)
	{
		free(path);
		print_builtin_error("cd: couldn't get current dir", "");
		return (-1);
	}
	/* Try to change the current dir */
	if (chdir(path) == -1)
	{
		free(path);
		print_builtin_error("cd: can't change cd to ", _path);
		set_custom_exit_code(1);
		return (-1);
	}
	/* Update env variables */
	free(path);
	set_process_exit_code(0);
	return (1);
}


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

	set_process_exit_code(0);
}
