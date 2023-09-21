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
		write(STDERR_FILENO, err_msg, strlen(err_msg));
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
 * Return: 0 on success
*/
int main(void)
{
	int read, exec_file = 0;
	char *buff = NULL;
	size_t buff_len = 0;
	int fd;


	/*update_count_lines();*/

	while (1)
	{
		/* Print console symbol only if it is interactive*/
		if (isatty(STDIN_FILENO) == 1 && exec_file == 0)
			write(STDOUT_FILENO, "$ ", 2);
		/* Read commands from console */
		/*read = read_line(fd, &buff);*/
		read = getline(&buff, &buff_len, stdin);
		if (read == EOF)
		{
			free(buff);
			exit(*process_exit_code());
		}
		/*handle_history(buff);*/
		/* Remove comments & '\n' char from buffer */
		buff = handle_comment(buff);
		_strtok(buff, "\n");
		/* Handling_semicolon, ||, && and executes inside of the function */
	}
	/* Free buffer memory */
	free(buff);
	if (exec_file)
		close(fd);
	return (*process_exit_code());
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
