#include "shell.h" 

static int line_count_alternate; 
/**
 * update_line_count - Counts the lines in a previous history file
 */
void update_line_count(void)
{
	char current_directory[512];
	char read_buffer[1024];
	int i, file_descriptor, characters_read;
	char *home_directory;

	line_count_alternate = 0;

	if (getcwd(current_directory, 512) == NULL)
		return;

	home_directory = get_environment_variable("HOME");
	if (home_directory == NULL)
		home_directory = "";

	if (chdir(home_directory) == -1)
		return;

	file_descriptor = open(".custom_shell_history", O_RDONLY);
	if (file_descriptor == -1)
		return;

	while ((characters_read = read(file_descriptor, read_buffer, 1024)) != -1)
	{
		if (characters_read == 0)
			break;

		for (i = 0; i < characters_read; i++)
			if (read_buffer[i] == '\n')
				line_count_alternate++;
	}

	chdir(current_directory);
}

/**
 * get_line_count_alternate - Returns the line count of a history file
 *
 * Return: Pointer to the line count
 */
int *get_line_count_alternate()
{
	return (&line_count_alternate);
}
