#include "shell.h"

/**
 * free_dbl_ptr - Frees the memory pointed to by a double pointer.
 *
 * @dbl_ptr: Double pointer.
 */
void free_dbl_ptr(char **dbl_ptr)
{
	int i;

	if (dbl_ptr == NULL)
		return;

	for (i = 0; dbl_ptr[i]; i++)
		free(dbl_ptr[i]);

	free(dbl_ptr);
}


/**
 * alloc_mem - Manages the allocation of memory.
 *
 * @bytes: Number representing the size in bytes to allocate.
 *
 * Return: Pointer to the newly allocated memory.
 */
void *alloc_mem(unsigned int bytes)
{
	char *new_mem = malloc(bytes);

	if (new_mem == NULL)
		dispatch_error("Error while allocating memory\n");

	return (new_mem);
}

/**
 * dup_str - Duplicates a given string.
 *
 * @str: String to duplicate.
 *
 * Return: Pointer to the address of the newly duplicated string.
 */
char *dup_str(char *str)
{
	char *str_copy = strdup(str);

	if (str_copy == NULL)
		dispatch_error("Error while making copy of string");

	return (str_copy);
}
