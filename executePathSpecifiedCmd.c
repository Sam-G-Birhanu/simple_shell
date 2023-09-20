extern char **environ;
#include "shell.h"
/**
 * executePathSpecifiedCmd - a function that exceutes command when path is specified
 * @tokens: pointer that points to command token
 * @programPath: parameter
 * Return: 0 if successful
 */

int executePathSpecifiedCmd(char *programPath, char **tokens)
{
	pid_t child = fork();
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		char *args[MAX_ARGUMENTS];
		int i;
		args[0] = programPath;
		for (i = 1; tokens[i] != NULL; i++)
		{
			args[i] = tokens[i];
		}
		args[i] = NULL;
		execve(programPath, args, environ);
		perror(programPath);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		wait(&status);
	}
	return (0);
}
