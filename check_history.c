#include "shell.h"

/* Global variables */
static int no_init_history;
static list_t *history_head;
static list_t *last_cmd;

/**
 * get_hist_add - Return the address oof history head
 *
 * Return: Address of history head
*/
list_t **get_hist_add()
{
	if (no_init_history == 1)
	{
		history_head = NULL;
		last_cmd = NULL;
		no_init_history = 0;
	}

	return (&history_head);
}

/**
 * get_last_cmd_add - Return the address oof history head
 *
 * Return: Address of last entered command
*/
list_t **get_last_cmd_add()
{
	if (no_init_history == 1)
	{
		history_head = NULL;
		last_cmd = NULL;
		no_init_history = 0;
	}

	return (&last_cmd);
}

/**
 * _hist - Prints the all the commands entered by the user
 *
 * Return: 1 on success
*/
int _hist(void)
{
	list_t *curr;
	char *strNum;
	int i, len;
	int count = *get_line_count_alternate() % 4096;

	for (curr = *get_hist_add(); curr != NULL; curr = curr->next)
	{
		strNum = num_to_str(count++);
		len = _puts(strNum);
		for (i = len; i < 7; i++) /* 5 per number, 2 aditional */
			_puts(" ");
		_puts(curr->str);
		_puts("\n");
		free(strNum);
	}

	return (1);
}

/**
 * handle_history - Adds a command to the history
 * @buff: User's input
*/
void handle_hist(char *buff)
{
	/* Only adds a command if is different from the previous one */
	if (last_cmd == NULL || buff[0] != ' ' || _strcmp(last_cmd->str, buff) != 0)
		last_cmd = add_node_end(get_hist_add(), buff);
}

/**
 * free_hist - Frees the memory used by history list
*/
void free_hist(void)
{
	free_list(*get_hist_add());
}
