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

extern char **environ;


char strcpy(pPath, token);
char strcat(pPath, "/");
char strcat(pPath, programName);
extern char **environ;
char *ORIGINAL_PATH;

int result;
char *programName;
char *token;
char *original_path = strdup(ORIGINAL_PATH);

/** extern char *ORIGINAL_PATH; **/
int main(void);
int prompt(void);
char **tokenize(const char *command);
int executeCommand(char **tokens);
int executePathSpecifiedCmd(char *programPath, char **tokens);
int fileExists(const char *filename);
int handleBuiltins(char **tokens);
#endif
