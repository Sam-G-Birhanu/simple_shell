#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pwd.h>
#define MAX_ARGUMENTS 128


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
void free_list(list_t *head);
char *get_first_av(void);
void __attribute__((constructor)) build_dynamic_environ(void);
void __attribute__((destructor)) free_dynamic_environ(void);
char *_getenv(char *name);
void handle_var_replacement(char **commands);
int *process_exit_code();
void set_process_exit_code(int code);
void env(void);
int _setenv(char *name, char *value);
int _unsetenv(char *name);
int _cd(char *path);
int _alias(char **commands);
int _help(char **commands);
int _history(void);
list_t **get_alias_head();
list_t **get_history_addrss();
list_t **get_last_cmd_addrss();
void handle_history(char *buff);
void free_history(void);
void write_history(void);
void update_count_lines(void);
int *get_history_lines_count();
int validate_env_name(char *name);
int is_valid_env_var_name(char *name);
int get_env_index(char *name);
void set_alias(char *alias_pair);
int is_set_alias(char *alias_pair);
int handle_alias_args(char **commands, list_t **out_addrs);
int read_line(const int fd, char **line);
int f_read_line(char **str, char **line, int fd);
char *_strtok(char *str, char *delimiter);
int _getline(char **buffer, size_t *buf_size, FILE *stream);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

/* Command handlers */
int handle_PATH(char **commands);
char *getpath(char *dir, char *filename);
char **parse_user_input(char *str_input, char *delimiter);
int count_args(char *str_input, char *delimiter);

/* Memory management */
void *allocate_memory(unsigned int bytes);
char *duplicate_string(char *str);
void free_dbl_ptr(char **dbl_ptr);
void free_allocs(char *buff, char **cmds_list, char **commands, int flags);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

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
void dispatch_error(char *msg);
void print_builtin_error(char *msg, char *arg);



#endif
