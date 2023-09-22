#ifndef SHELL
#define SHELL

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define MAX_ARGUMENTS 128

/* FLAGS */
#define F_BUFF 1
#define F_CMD_L 2
#define F_CMDS 4

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;







/*linked lists*/
size_t print_list(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);

char *getfirst(void);



void __attribute__((constructor)) build_dynamic_environ(void);
void __attribute__((destructor)) free_dynamic_environ(void);
char *get_environment_variable(char *var_name);
void handle_variable_substitution(char **command_args);
int *get_exit_code_alternate();
void set_custom_exit_code(int code);
void env(void);
int set_env(char *name, char *value);
int unset_env(char *name);
int _cd(char *path);
int _alias(char **commands);
int fun_help(char **commands);
int _hist(void);

list_t **get_alias_head();
list_t **get_hist_add();
list_t **get_last_cmd_add();

void handle_hist(char *buff);

void free_hist(void);
void free_linked_list(list_t *head);
void write_history_to_file_in_home_dir(void);
void update_line_count(void);
int *get_line_count_alternate();

int validate_env_var_name(char *name);
int is_valid_env_var_name(char *name);
int get_env_var_index(char *name);
void set_alias(char *alias_pair);
int is_set_alias(char *alias_pair);
int handle_alias_args(char **commands, list_t **out_addrs);
int fun_read_line(const int f_d, char **line);
int new_read_line(char **str, char **line, int f_d); 

char *split_string(char *str, char *delimiter);
int _getline(char **buffer, size_t *buf_size, FILE *stream);
char *_strcpy(char *destination, char *source);
char *_strncpy(char *destination, char *source, int num);

/* Command handlers */
int handle_PATH(char **commands);
char *getpath(char *dir, char *filename);
char **parse_user_input(char *str_input, char *delimiter);
int count_args(char *str_input, char *delimiter);

/* Memory management */
void *alloc_mem(unsigned int bytes);
char *dup_str(char *str);
void free_dbl_ptr(char **dbl_ptr);
void free_allocated(char *buff, char **cmds_list, char **commands, int flags);

void *fun_reallocate(void *ptr, unsigned int former_size, unsigned int current_size);

/* handle_builtins */
int handle_builtins(char **commands);

/* handle_enter */
int handle_enter(char **commands);
/* handle comments in input */
char *handle_comment();

/* Exit handlers */
int handle_exit(char *buff, char **cmds_list, char **commands);
int get_exit_status(char *buff);

/* Error handlers */
void dispatchError(char *msg);
void printError(char *msg, char *arg);


void mem_del(void **ap);


int _strleng(const char *str);
char *_strdup(const char *str1);
char *str_cat(char *str1, const char *str2);
char *str_chr(const char *str, int char_to_search);


char *int_to_str(int num);
int _strncmp(const char *str1, const char *str2, size_t n);
int _puts(char *strng);



char *str_join(char const *str1, char const *str2);
char *str_sub(char const *str, unsigned int start, size_t len);
void str_del(char **as);
int _strcmp(const char *str1, const char *str2);





#endif
