#include "shell.h"
/*
 * fileExists - a function that checks whether an executable exists
 * @filename: a parmeter
 * Return: type int
 */

int fileExists(const char *filename) {
    if (access(filename, F_OK) == 0) {
        return 1;  // File exists
    } else {
        return 0;  // File does not exist
    }
}

