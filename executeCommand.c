#include "shell.h"

extern char **environ;
char *ORIGINAL_PATH = getenv("PATH");
int executeCommand(char **tokens) {
	int result;
	char *programName;
	char *token;
	char *original_path = strdup(ORIGINAL_PATH);
	if (strcmp(tokens[0], "exit") == 0) {
		exit(0);
	}


	result = handleBuiltins(tokens);

	if (result != -1) {
		setenv("PATH", original_path, 1);
		return result;
	}


	programName = tokens[0];
	token = strtok(original_path, ":");
	if (programName[0] == '/')
	{
		if (fileExists(programName)) {
		    executePathSpecifiedCmd(programName, tokens);
		    return -1;
		}
	}
	while (token != NULL)
	{
		char *programPath = malloc(strlen(token) + strlen("/") + strlen(programName) + 1);
		if (programPath == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(programPath, token);
		strcat(programPath, "/");
		strcat(programPath, programName);


		if (fileExists(programPath)) {
			pid_t child = fork();

			if (child == -1) {
				perror("fork");
				exit(EXIT_FAILURE);
			}

			if (child == 0) {


				char *args[MAX_ARGUMENTS];
				int i; 
				setenv("PATH", original_path, 1);

				args[0] = programPath;


				for (i = 1; tokens[i] != NULL; i++) {
					args[i] = tokens[i];
				}

				args[i] = NULL;

				execve(programPath, args, environ);
				free(programPath);
				perror(".hsh");
				exit(EXIT_FAILURE);
			} else {
				int status;
				wait(&status);

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
