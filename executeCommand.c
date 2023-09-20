#include "shell.h"

extern char **environ;
extern char *ORIGINAL_PATH;
int executeCommand(char **tokens)
{
	char *original_path = ORIGINAL_PATH;
	int result = handleBuiltins(tokens);
	char *programName = tokens[0];
	char *token = strtok(original_path, ":");

	if (strcmp(tokens[0], "exit") == 0) {
		exit(0);
	}


/**	char originalDirectory[1024];

	if (getcwd(originalDirectory, sizeof(originalDirectory)) == NULL) {
		perror("getcwd");
		return -1;
	}
**/

	if (result != -1) {
		setenv("PATH", original_path, 1);
		return result;
	}

	if (programName[0] == '/')
	{
				printf("%s original path" ,original_path);

		if (fileExists(programName)) {
		    executePathSpecifiedCmd(programName, tokens);
		    return -1;
		}
	}
	while (token != NULL)
	{
				char *programPath = malloc(strlen(token) + strlen("/") + strlen(programName) + 1);
		printf("%s original path" ,original_path);

		if (programPath == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(programPath, token);
		strcat(programPath, "/");
		strcat(programPath, programName);

		if (fileExists(programPath))
		{
			pid_t child = fork();

			if (child == -1) {
				perror("fork");
				exit(EXIT_FAILURE);
			}

			if (child == 0) {
				char *args[MAX_ARGUMENTS];
				int i;
				
				args[0] = programPath;
				
				
				/** if (chdir(originalDirectory) == -1)
				{
					perror("chdir");
					exit(EXIT_FAILURE);
				}
				**/

				setenv("PATH", original_path, 1);

				

				for (i = 1; tokens[i] != NULL; i++)
				{
					args[i] = tokens[i];
				}

				args[i] = NULL;

				execve(programPath, args, environ);
				free(programPath);
				perror(".hsh");
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

				free(programPath);
				return 0;
			}
		}

		free(programPath);
		token = strtok(NULL, ":");
	}

	perror(".hsh");
	return -1;
}

