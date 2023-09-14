#include "mainheader.h"

/**
 * mem_del - function that free an array
 * @ap: array of strings
 * Return: void
 */
void mem_del(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

/**
 * str_del - function that delete an array of strings
 * @as: array of strings
 * Return: void
 */
void str_del(char **as)
{
	mem_del((void **)as);
}

/**
 * str_join - concatenates string 1 + string 2
 * @str1: string 1
 * @str2: string 2
 * Return: copy of string with null terminated char
 */
char *str_join(char const *str1, char const *str2)
{
	size_t	len3;
	char	*str3;

	if (!str1 || !str2)
		return (NULL);
	len3 = strlen(str1) + strlen(str2);
	str3 = malloc(len3 + 1);
	if (str3 == NULL)
		return (NULL);
	str3[0] = '\0';
	strcat(str3, str1);
	strcat(str3, str2);
	str3[len3] = '\0';
	return (str3);
}

/**
 * str_sub - function that substract a paragraph from string
 * @str: string
 * @start: index of start
 * @len: len of characters to do a copy
 * Return: copy of string with null terminated char
 */
char *str_sub(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_str;

	new_str = (char *)malloc(len + 1);
	if (str == NULL || new_str == NULL)
		return (NULL);
	i = 0;
	while (len-- && str[start + i])
	{
		new_str[i] = str[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
