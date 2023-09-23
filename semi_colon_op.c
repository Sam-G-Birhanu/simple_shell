#include "shell.h"

void handle_aliases(char **commands);
void handle_cmd_not_found(char *buff, char **cmdl, char **commands,
	char *first_av);

/**
 * handling_semicolon_and_operators - Handle semicolon and logical op
 * @buff: first buffer that functions read
 * @read: return of read (open with getline)
 * @first_av: av[0]
 * Return: 0 on success
*/
void handling_semicolon_and_operators(char *buff, int read, char *first_av)
{
	/* int i; */
	/*char **cmdl = parse_user_input(buff, ";");*/
	char **cmdl = NULL;

	execute_commands(buff, cmdl, buff, read, first_av);
	/* for (i = 0; cmdl[i] != NULL; i++) */
		/*handling_or(cmdl[i], read, first_av);*/
	/* free_dbl_ptr(cmdl); */
}

/**
 * handling_or - Handle || logical part
 * @buff_semicolon: first buffer that functions read
 * @read: return of read (open with getline)
 * @first_av: av[0]
 * Return: 0 on success
*/
void handling_or(char *buff_semicolon, int read, char *first_av)
{
	int i, flag, prev_flag = -1;
	char **cmdl_2 = parse_user_input(buff_semicolon, "||");

	for (i = 0; cmdl_2[i] != NULL; i++)
	{
		flag = handling_and(cmdl_2[i], read, first_av, prev_flag);
		/* record de last*/
		prev_flag = flag;
	}
	free_dbl_ptr(cmdl_2);
}

/**
 * handling_and - Handle && logical part and executes inside of it
 * @buff_or: first buffer that functions read
 * @read: return of read (open with getline)
 * @first_av: av[0]
 * @prev_flag: last flag of ||, it is important to print or not
 * Return: 0 on success
*/
int handling_and(char *buff_or, int read, char *first_av, int prev_flag)
{
	int j = 0, flag = 1;
	char **cmdl_3 = parse_user_input(buff_or, "&&");

	/* logical part: if the last || is success, */
	/*	next -> &&; if not exist &&, return */
	if (prev_flag == 0)
	{
		j++;
		if (cmdl_3[j] == NULL)
			return (-1);
	}

	for (; cmdl_3[j] != NULL; j++)
	{
		flag = execute_commands(buff_or, cmdl_3,
									cmdl_3[j], read, first_av);
		prev_flag = flag;
	}
		/* record de last result , estudiar el caso 0 */
	free_dbl_ptr(cmdl_3);
	return (flag);
}

/**
 * execute_commands - Fork and create commands, child process and executed
 * @b: first buffer that function read
 * @c: List of commands
 * @cmd: Single command as a string
 * @r: return of read (open with getline)
 * @ft_av: av[0]
 * Return: 0 on success
*/
<<<<<<< HEAD
int execute_commands(char *buff, char **cmdl, char *cmd,int __attribute__((unused))read, char *first_av)
=======
int execute_commands(char *b, char **c, char *cmd, int __attribute__((unused))r, char *ft_av)
>>>>>>> 4a93a889ade6db4030ee07b364f3fa452d3e8eeb
{
	char **commands;
	int child_pid, _err = 0, flag = 0, *status = get_exit_code_alternate();

	/* Generate array of commands */
	commands = parse_user_input(cmd, " ");
	handle_variable_substitution(commands);
	handle_aliases(commands);
	/* Exit error, ENTER, and builtins */
	if (exit_shell(b, c, commands) == -1 ||
			handleEnter(commands) == 1	||
			handle_builtins(commands) == 1)
	{
		free_dbl_ptr(commands);
		return (-1);
	}
	/* check if we can only run for positives */
	child_pid = fork();/* Fork parent process to execute the command */
	if (child_pid == -1)
	{
		free_allocated(b, c, commands, F_BUFF | F_CMD_L | F_CMDS);
		dispatchError(ft_av);
	}
	else if (child_pid == 0)
	{
		_err = handle_PATH(commands);
		execve(commands[0], commands, __environ);
		if (_err != 0)
			handle_cmd_not_found(b, c, commands, ft_av);
		free_allocated(b, c, commands, F_BUFF | F_CMD_L | F_CMDS);
		dispatchError(ft_av);
	}
	wait(status);
	*status = WEXITSTATUS(*status);
	if (*status == 2)
		set_custom_exit_code(127);
	free_dbl_ptr(commands);
	return (flag);
}

/**
 * handle_cmd_not_found - Print a message to stderr
 * @buff: User's input
 * @cmdl: Array of commands
 * @commands: Array of strings
 * @first_av: First argument passed to the executable
*/
void handle_cmd_not_found(char *buff, char **cmdl, char **commands,
	char *first_av)
{
	set_custom_exit_code(127);
	write(2, first_av, _strleng(first_av));
	write(2, ": 1: ", 5);
	write(2, commands[0], _strleng(commands[0]));
	write(2, ": not found\n", 12);
	free_allocated(buff, cmdl, commands, F_BUFF | F_CMD_L | F_CMDS);
	exit(127);
}
