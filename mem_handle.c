#include "shell.h"

/**
 * fun_reallocate - Reallocates a memory block
 * @ptr: Pointer to the memory to be reallocated
 * @f_size: Size in bytes of the actual allocated memory
 * @c_size: Size in bytes for the new allocated memory
 *
 * Return:Pointer to the newly allocated memory
 */
void *fun_reallocate(void *ptr, unsigned int f_size, unsigned int c_size)
{
	int limit, i;
	void *pointer;

	if (f_size == c_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(c_size));

	if (c_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	pointer = malloc(c_size);

	if (f_size > c_size)
		limit = c_size;
	else
		limit = f_size;

	for (i = 0; i < limit; i++)
		((char *)pointer)[i] = ((char *)ptr)[i];

	free(ptr);

	return (pointer);
}
