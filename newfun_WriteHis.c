#include "shell.h"

/**
 * write_history_to_file_in_home_dir - Writes the history to a file in the user's home directory
*/
void write_history_to_file_in_home_dir(void)
{
	char *home;

	home = _getenv("HOME");
	if (home == NULL)
		home = "/";
}
