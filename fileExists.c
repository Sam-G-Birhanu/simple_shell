#include "shell.h"
/*
 * fileExists - a function that checks whether an executable exists
 * @filename: a parmeter
 * Return: type int
 */

int fileExists(const char *filename) {
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
}
