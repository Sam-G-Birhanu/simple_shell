#include "shell.h"

/**
 * prompt - Ccpoies a string
 * @void: String to wich chars are going to be copied
 *
 * Return: Pointer to dest
 */
int prompt(void)
{
	char *line = NULL;
	size_t leng = 0;
	ssize_t read;

	while (1)
	{
		char **tokens;
		int i;

		printf("$ ");
		read = getline(&line, &leng, stdin);

		if (read == -1)
		{
			perror("getline");
			break;
		}
		line[strlen(line) - 1] = '\0';
		tokens = tokenize(line);

		if (tokens == NULL)
		{
			perror("tokenize");
			break;
		}
		executeCommand(tokens);

		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
	free(line);
	return (0);
}
