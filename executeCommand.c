#include "shell.h"

/**
 * executeCommand - Ccpoies a string
 * @tokens: String to wich chars are going to be copied
 *
 * Return: Pointer to dest
 */
int executeCommand(char **tokens)
{
	result = handleBuiltins(token);
	programName = tokens[0];
	token = strtok(original_path, ":");

	while (token != NULL)
	{
		char *pPath = malloc(strlen(token) + strlen("/") + strlen(programName) + 1);

		if (fileExists(programPath))
		{
			pid_t child = fork();

			if (child == 0)
			{
				char *args[MAX_ARGUMENTS];
				int i;

				setenv("PATH", original_path, 1);
				args[0] = programPath;

				for (i = 1; tokens[i] != NULL; i++)
				{
					args[i] = tokens[i];
				}
				args[i] = NULL;
				execve(programPath, args, environ);
				free(programPath);
				perror(".hsh");
				exit(EXIT_FAILURE);
			} else
			{
				int status;

				wait(&status);
				free(programPath);
				return (0); }}}}
