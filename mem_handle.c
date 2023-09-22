#include "shell.h"

/**
 * fun_reallocate - Reallocates a memory block
 * @ptr: Pointer to the memory to be reallocated
 * @former_size: Size in bytes of the actual allocated memory
 * @current_size: Size in bytes for the new allocated memory
 *
 * Return:Pointer to the newly allocated memory
 */
void *fun_reallocate(void *ptr, unsigned int former_size, unsigned int current_size)
{
	int limit, i;
	void *pointer;

	if (former_size == current_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(current_size));

	if (current_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	pointer = malloc(current_size);

	if (former_size > current_size)
		limit = current_size;
	else
		limit = former_size;

	for (i = 0; i < limit; i++)
		((char *)pointer)[i] = ((char *)ptr)[i];

	free(ptr);

	return (pointer);
}
