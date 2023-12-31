#include "shell.h"

/**
 * exit_shell - Checks if the user entered the exit command
 * @buff: User's input
 * @cmds_list: Array of parsed commands
 * @commands: User's input parsed as array of commands
 *
 * Return: 0 if the commad is NOT exit, -1 if the exit status was Illegal
*/
int exit_shell(char *buff, char **cmds_list, char **commands)
{
	int status;

	/* Command is NOT exit */
	if (commands[0] == NULL || strcmp(commands[0], "exit") != 0)
		return (0);

	/* Command is exit */
	if (commands[1] == NULL)
	{
		write_history_to_file_in_home_dir();
		free_allocated(buff, cmds_list, commands, F_BUFF | F_CMDS);
		if (*get_exit_code_alternate() == 127)
			exit(2);
		exit(0);
	}

	status = get_exit_status(commands[1]);
	/* Command is exit status */
	if (status >= 0)
	{
		write_history_to_file_in_home_dir();
		free_allocated(buff, cmds_list, commands, F_BUFF | F_CMDS);
		exit(status);
	}

	/* the exit status passed was illegal */
	printError("exit: Illegal number: ", commands[1]);
	return (-1);
}

/**
 * get_exit_status - Calculates the exit status as a number
 * @buff: User's input
 *
 * Return: Exist status as number, -1 on error
*/
int get_exit_status(char *buff)
{
	int i;
	int status = 0;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '\n')
			return (status);

		if (buff[i] < '0' || buff[i] > '9')
			return (-1);

		status *= 10;
		status += buff[i] - '0';
	}

	return (status);
}
