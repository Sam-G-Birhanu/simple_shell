#include "mainheader.h"

/**
 * free_environment_array - Frees the memory allocated to hold "env vars"
 */
void free_environment_array(void)
{
	free_dbl_ptr(__environ);
}

/**
 * build_environment_array - Builds the "env vars" array using dynamic memory
*/
void build_environment_array(void)
{
	int e_var_count = 0;
	char **new_e_var;

	while (__environ[e_var_count] != NULL)
		e_var_count++;

	new_e_var = allocate_memory(sizeof(char *) * (e_var_count + 1));
	for (e_var_count = 0;  __environ[e_var_count] != NULL; e_var_count++)
		new_e_var[e_var_count] = duplicate_string(__environ[e_var_count]);

	/* Last element should be NULL */
	new_e_var[e_var_count] = NULL;
	/* Asign new memory dynamically allocated */
	__environ = new_e_var;
}
