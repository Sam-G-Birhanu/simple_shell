#include "shell.h" 

/**
 * handle_variable_substitution - Handles dollar variable substitutions '$'
 * @command_args: Array of command arguments
 */
void handle_variable_substitution(char **command_args)
{
	int i;
	char *env_value;

	if (command_args[0] == NULL)
		return;

	/* Scan command arguments and perform variable substitutions using PATH, $$, $? */
	for (i = 1; command_args[i] != NULL; i++)
	{
		if (command_args[i][0] != '$')
			continue;
		/* Here, the argument starts with '$' */

		if (_strcmp(&command_args[i][1], "?") == 0)
		{
			free(command_args[i]);
			command_args[i] = num_to_str(*get_exit_code_alternate()); 
			return;
		}

		if (_strcmp(&command_args[i][1], "$") == 0)
		{
			free(command_args[i]);
			command_args[i] = num_to_str(getpid());
			return;
		}

		env_value = get_environment_variable(&command_args[i][1]);
		if (env_value != NULL)
		{
			free(command_args[i]);
			command_args[i] = duplicate_string(env_value);
		}
	}
}
