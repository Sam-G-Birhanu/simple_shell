#include "shell.h"
/**
 * tokenize - a function that returns a tokenozed version of the input command
 * command: a parameter passed in to be tokenized
 * Return: it returns a pointer to an array of tokens
 */

char **tokenize(const char *command)
{
	char **tokens = malloc(sizeof(char *) * 128);
	if (tokens == NULL)
	{
		return NULL;
	}
	int i = 0;
	char *token = strtok((char *)command, " ");
	
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	
	tokens[i] = NULL;
	return tokens;
}
