#include "shell.h"
#include <errno.h>

/**
 * printError - Prints error for buitin function
 * @msg: Error message
 * @arg: Argument passed to builtin
*/
void printError(char *msg, char *arg)
{
	int len = strlen(msg);
	char *first_av = get_first_av();

	write(STDERR_FILENO, first_av, strlen(first_av));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, msg, len);
	write(STDERR_FILENO, arg, strlen(arg));
	write(STDERR_FILENO, "\n", 1);
	set_process_exit_code(2);
}

/**
 * dispatchError - Dispatches an error
 * @msg: Message to print as error
*/
void dispatchError(char *msg)
{
	/* int len = _strlen(msg); */
	perror(msg);
	/*write(STDERR_FILENO, msg, len);*/
	/*write(STDERR_FILENO,": not found\n", 12);*/
	exit(errno);
	/*exit(127); */
}
