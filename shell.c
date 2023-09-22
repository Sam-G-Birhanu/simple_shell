#include "shell.h"

static char *FIRST_ARG;

void sigint_H(int sig_num);
char *getfirst();
int handle_arg(int ac, char **av, int *exec_file);


/**
 * handle_arg - Check the number of arguments passed to main
 * @ac: Number of arguments
 * @av: Array of arguments as strings
 * @exec_file: Integer used to check if user wants to exec commands from file
 *
 * Return: File descriptor to file
*/
int handle_arg(int ac, char **av, int *exec_file)
{
	int fd = STDIN_FILENO;
	char *err_msg = "Error: more than one argument\n";

	if (ac > 2)
	{
		write(STDERR_FILENO, err_msg, _strleng(err_msg));
		exit(1);
	}
	if (ac == 2)
	{
		*exec_file = 1;
	}
	if (fd == -1)
	{
		perror(av[0]);
		exit(1);
	}

	return (fd);
}

/**
 * main - Entry point
 * @ac: Number of arguments
 * @av: Array of arguments as strings
 * Return: 0 on success
*/
int main(int ac, char **av)
{
	int read, exec_file = 0;
	char *buff = NULL;
	size_t buff_len = 0;
	int fd;

	FIRST_ARG = av[0];
	signal(SIGINT, sigint_H);
	fd = handle_arg(ac, av, &exec_file);

	/*update_count_lines();*/

	while (1)
	{
		/* Print console symbol only if it is interactive*/
		if (isatty(STDIN_FILENO) == 1 && exec_file == 0)
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&buff, &buff_len, stdin);
		if (read == EOF)
		{
			free(buff);
			exit(*get_exit_code_alternate());
		}

		buff = remove_comment(buff);
		split_string(buff, "\n");
		handling_semicolon_and_operators(buff, read, av[0]);

	}
	/* Free buffer memory */
	free(buff);
	if (exec_file)
		close(fd);
	return (*get_exit_code_alternate());
}



/**
 * sigint_H - Avoids current process to finish
 * @sig_num: Signal number
*/
void sigint_H(int __attribute__((unused))sig_num)
{
	write(STDIN_FILENO, "\n$ ", 3);
}

/**
 * getfirst - Returns the first argument passed to main
 *
 * Return: Pointer to first arg passed to main
*/
char *getfirst(void)
{
	return (FIRST_ARG);
}
