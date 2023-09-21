#include "shell.h"


/**
 * str_cat - concatenate two strings
 * @str1: string 1
 * @str2: string 2
 * Return: return a pointer to the resulting string dest.
 */
char *str_cat(char *str1, const char *str2)
{
	return (str_cat(str1, str2));
}

/**
 * str_ncat - concatenate first n chars of str2 to str1 string
 * @str1: string 1
 * @str2: string 2
 * @n: numbers of characters of str2 to concatenate to the str1
 * Return: return a pointer to the resulting string dest.
 */
char *str_ncat(char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;

	i = strlen(str1);
	j = 0;
	while (str2[j] && j < n)
		str1[i++] = str2[j++];
	str1[i] = '\0';
	return (str1);
}

/**
 * str_chr - string scanning operation
 * @str: string 1
 * @char_to_search: character to search
 * Return: return a pointer to the byte, or
 * a null pointer if the byte was not found.
 */
char *str_chr(const char *str, int char_to_search)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == char_to_search)
			return ((char *)&str[i]);
		i++;
	}
	if (char_to_search == '\0')
		return ((char *)(&str[i]));
	return (NULL);
}
