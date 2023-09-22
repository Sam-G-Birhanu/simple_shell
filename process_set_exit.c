#include "shell.h"

static int exit_code_alternate; 
static int is_exit_code_initialized = 1; 

/**
 * get_exit_code_alternate - Retrieves the address of the exit_code_alternate variable
 *
 * Return: Address of the exit_code_alternate variable
 */
int *get_exit_code_alternate()
{
	if (is_exit_code_initialized)
	{
		exit_code_alternate = 0; 
		is_exit_code_initialized = 0; 
	}

	return (&exit_code_alternate); 
}

/**
 * set_exit_code_alternate - Sets a new value for the exit_code_alternate variable
 * @code: The integer value representing the alternate exit code
 */
void set_exit_code_alternate(int code)
{
	exit_code_alternate = code; 
}