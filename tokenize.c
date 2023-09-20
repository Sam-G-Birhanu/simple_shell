#include "shell.h"
/**
 * tokenize - a function that returns a tokenozed version of the input command
 * command: a parameter passed in to be tokenized
 * Return: it returns a pointer to an array of tokens
 */

char **tokenize(const char *command)
{
	int i = 0;
	char *token;
	
	char **tokens = malloc(sizeof(char *) * 128);
	
	if (tokens == NULL)
	{
		perror("malloc");
		return NULL;
	}
	if (command == NULL)
	{
		return NULL;
	}

	token = strtok((char *)command, " ");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
        {
		int j;
            perror("strdup");
            for ( j = 0; j < i; j++)
            {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
		i++;
		token = strtok(NULL, " ");
	}
	
	tokens[i] = NULL;
	return tokens;
}
