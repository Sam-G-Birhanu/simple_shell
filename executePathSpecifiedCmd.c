#include "shell.h"


/**
 * add_node_to_end - Adds a new node to the end of a linked list.
 *
 * @head: A pointer to the head of the linked list.
 * @str: The content of the string for the first node.
 *
 * Return: A pointer to the new node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end_node, *tmp;

	end_node = malloc(sizeof(list_t));

	if (end_node == NULL)
		return (NULL);

	end_node->str = strdup(str);
	end_node->len = _strleng(str);
	end_node->next = NULL;

	if (*head == NULL)
	{
		*head = end_node;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = end_node;
	return (end_node);

}

/**
 * free_linked_list - Frees the memory allocated for a linked list.
 *
 * @head: Head of first node.
 *
 * Return: void -> free the linked list.
 */
void free_linked_list(list_t *head)
{
	if (head == NULL)
		return;
	free_linked_list(head->next);
	free(head->str);
	free(head);
}

/**
 * print_list_nodes - Prints the contents of a linked list to the console.
 *
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_list_nodes(const list_t *head)
{
	unsigned int number_nodes = 0;

	while (head != NULL)
	{
		if (head->str)
		{
			puts(" ");
			puts(head->str);
			puts("\n");
		}
		else
			puts("[0] (nil)\n");
		head = head->next;
		number_nodes++;
	}
	return (number_nodes);
}
