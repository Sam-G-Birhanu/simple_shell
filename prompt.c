#include "shell.h"                                                                                                                                                        /**                                                                                                                                                                      * prompt - a function that prompts the user to input command                                                                                                            * tokens: is a parameter                                                                                                                                                * Return: it returns input type of int                                                                                                                                  */ 

int prompt(const char *originalPath) {
	char *line = NULL;
	size_t leng = 0;
	ssize_t read;
	
	while (1)
	{
		char **tokens;
		int i;
		
		printf("$ ");
		
		read = getline(&line, &leng, stdin);
		tokens = tokenize(line);

		if (read == -1)
		{
						printf("I am above getline");
			perror("getline");
			break;
		}
		
		line[strlen(line) - 1] = '\0';
		if (tokens == NULL)
		{
			printf("I am above tokenize");
			perror("tokenize");
			break;
		}
printf("I am above exc command");
		executeCommand(tokens, originalPath);
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
	
	free(line);
	
	return 0;
}
