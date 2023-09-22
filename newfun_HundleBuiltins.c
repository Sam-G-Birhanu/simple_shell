#include "shell.h"

int environment_builtins(char **commands);
int other_builtins(char **commands);

/**
 * handle_builtins - Executes the builtin funtions in case the command is one
 * @commands: User's input parsed as an array of commads
 *
 * Return: 1 if the command is a builtin, 0 otherwise
*/
int handle_builtins(char **commands)
{
	if (commands[0] == NULL)
		return (0);

	if (environment_builtins(commands))
		return (1);

	if (other_builtins(commands))
		return (1);

	return (0);
}

/**
 * environment_builtins - Verifies if a command is a builtin
 * @commands: Arrays of commnads
 *
 * Return: 1 if command is a builtin, 0 otherwise
*/
int environment_builtins(char **commands)
{
	if (strcmp(commands[0], "env") == 0)
	{
		if (commands[1] != NULL)
			return (0);

		env();
		return (1);
	}

	if (strcmp(commands[0], "setenv") == 0)
	{
		if (commands[1] == NULL || commands[2] == NULL || commands[3] != NULL)
			return (1);

		_setenv(commands[1], commands[2]);
		return (1);
	}

	if (strcmp(commands[0], "unsetenv") == 0)
	{
		if (commands[1] == NULL || commands[2] != NULL)
			return (1);

		_unsetenv(commands[1]);
		return (1);
	}

	return (0);
}

/**
 * other_builtins - Verifies if a command is a builtin
 * @commands: Arrays of commnads
 *
 * Return: 1 if command is a builtin, 0 otherwise
*/
int other_builtins(char **commands)
{
	if (strcmp(commands[0], "cd") == 0)
	{
		char *path = commands[1];

		if (commands[1] == NULL)
			path = get_environment_variable("HOME");

		if (path == NULL)
			path = "/";

		_cd(path);
		return (1);
	}

	if (strcmp(commands[0], "alias") == 0)
	{
		_alias(commands);
		return (1);
	}

	if (strcmp(commands[0], "help") == 0)
	{
		get_help(commands);
		return (1);
	}

	if (strcmp(commands[0], "history") == 0)
	{
		if (commands[1] != NULL)
		{
			printError("history: No args allowed", "");
			return (1);
		}

		/*_history();*/
		/*return (1);*/
	}

	return (0);
}
