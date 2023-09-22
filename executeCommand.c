#include "shell.h"


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
	int env_var_count = 0;
	char **new_env_var;

	while (__environ[env_var_count] != NULL)
		env_var_count++;

	new_env_var = alloc_mem(sizeof(char *) * (env_var_count + 1));
	for (env_var_count = 0;  __environ[env_var_count] != NULL; env_var_count++)
		new_env_var[env_var_count] = duplicate_string(__environ[env_var_count]);

	/* Last element should be NULL */
	new_env_var[env_var_count] = NULL;
	/* Asign new memory dynamically allocated */
	__environ = new_env_var;
}
