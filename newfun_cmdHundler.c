#include "shell.h"

/**
 *  handle_PATH - Checks if the cmd could be fnd
 *  @commands: Array of strings containing the command and args
 *  Return: flag 0 if is succes; -1 if is error
 */
int handle_PATH(char **commands)
{
	char *path_dirs, *path;
	char *tkn, *tkn_ptr;
	char *str_copy;
	int flag = 127;

	if (
		commands == NULL || commands[0] == NULL ||
		commands[0][0] == '\0' || commands[0][0] == '/'
	)
		return (127);

	if (access(commands[0], F_OK) == 0)
		return (0);

	path_dirs = get_environment_variable("PATH");
	if (path_dirs == NULL)
		return (127);

	str_copy = dup_str(path_dirs);
	tkn_ptr = str_copy;
	while (1)
	{
		tkn = split_string(tkn_ptr, ":");
		if (tkn == NULL)
			break;
		tkn_ptr = NULL;
		path = getpath(tkn, commands[0]);
		if (access(path, F_OK) != -1)
		{
			free(commands[0]);
			commands[0] = path;
			flag = 0;
			break;
		}
		free(path);
	}
	free(str_copy);
	return (flag);
}

/**
 * getpath - Creates a string representing a full path to file
 * @dir: String representing a directory path
 * @filename: Name of the file we are looking for
 * Return: String as a full path to "filename"
 */
char *getpath(char *dir, char *filename)
{
	int dir_len = _strleng(dir);
	int filename_len = _strleng(filename);
	char *path;

	path = alloc_mem(sizeof(char *) * (dir_len + filename_len + 2));

	strcpy(path, dir);
	strcat(path, "/");
	strncat(path, filename, filename_len + 1);

	return (path);
}


/**
 * parse_user_input - Builds an array of strings as arguments
 * @str_input: Command input given by the user
 * @delimiter: String of characters indicating the delimiters
 * Return: Array of strings
 */
char **parse_user_input(char *str_input, char *delimiter)
{
	int i, args_count = 0;
	char **args;
	char *token, *tkn_ptr;
	char *str_copy;

	if (str_input == NULL)
		dispatchError("Error while parsing the command\n");

	/* Count the number of arguments present in the input */
	args_count = count_args(str_input, delimiter);
	/* Allocate memory to hold each argument as a string */
	args = alloc_mem(sizeof(char *) * (args_count + 1));
	/* Store each argument as a string */
	str_copy = dup_str(str_input);
	tkn_ptr = str_copy;
	for (i = 0; i < args_count; i++)
	{
		token = split_string(tkn_ptr, delimiter);
		if (token == NULL)
			break;
		tkn_ptr = NULL;
		/* store command as single string */
		args[i] = dup_str(token);
	}
	/* set the last element of array of arguments to NULL */
	args[i] = NULL;

	free(str_copy);

	return (args);
}

/**
 * count_args - Counts the number of arguments in a command string
 * @str_input: Command as a string
 * @delimiter: Delimiter by which to separate the args
 * Return: Number of arguments present in str_input
 */
int count_args(char *str_input, char *delimiter)
{
	char *tkn, *tkn_ptr;
	int count = 0;
	char *str_copy = dup_str(str_input);

	tkn_ptr = str_copy;
	while ((tkn = split_string(tkn_ptr, delimiter)) != NULL)
	{
		count++;
		tkn_ptr = NULL;
	}

	free(str_copy);

	return (count);
}

