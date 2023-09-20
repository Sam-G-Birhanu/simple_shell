#include "shell.h"

/**
 * executePathSpecifiedCmd - a function that exceutes.
 * @tokens: pointer that points to command token
 * @programPath : this is the desription.
 * Return: 0 if successful
 */

int executePathSpecifiedCmd(char *programPath, char **tokens)
{
/**	    char *programName = tokens[0]; **/
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

	if (WIFEXITED(status))
	{
		printf("Child process exited with status %d\n", WEXITSTATUS(status));
	}
	}
	return (0);
}
