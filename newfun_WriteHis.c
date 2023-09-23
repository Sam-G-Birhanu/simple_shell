#include "shell.h"

/**
 * write_history_to_file_in_home_dir - Writes the history to a file
*/
void write_history_to_file_in_home_dir(void)
{
	char *home;

	home = get_environment_variable("HOME");
	if (home == NULL)
		home = "/";
}
