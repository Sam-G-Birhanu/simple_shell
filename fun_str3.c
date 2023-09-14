#include "mainheader.h"


/**
 * num_to_str - Convert a number to string format
 * @num: Number to be converted
 *
 * Return: Pointer to string representation of "num"
*/
char *num_to_str(int num)
{
	int num_rev = 0;
	int i, digits = 0;
	char *num_str = NULL;

	if (num == 0)
		digits = 1;
	else
		while (num > 0)
		{
			digits++;
			num_rev *= 10;
			num_rev += num % 10;
			num /= 10;
		}

	num_str = malloc(sizeof(char) * (digits + 1));
	if (num_str == NULL)
		dispatch_error("Error: Coudn't allocate memory for number conversion");

	for (i = 0; i < digits; i++)
	{
		num_str[i] = (num_rev % 10) + '0';
		num_rev /= 10;
	}
	num_str[i] = '\0';

	return (num_str);
}

/**
 * str_len - returns the length of a string
 * @str: string
 * Return: length
 */
int str_len(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i])
		i++;
	return (i);
}

/**
 * str_dup - copy a strings with a malloc
 * @str1: string
 * Return: pointer to the copy
 */
char *str_dup(const char *str1)
{
	char	*str2;
	size_t	i;

	i = 0;
	str2 = (char *)malloc(sizeof(char) * str_len(str1) + 1);
	if (!str2)
		return (NULL);
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

/**
 * str_ncmp - compare if is equal 2 strings, first n chars
 * @str1: string1
 * @str2: string2
 * @n: n first characters
 * Return: 0 success; else pointer
 */
int	str_ncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && str1 && str2 && str1[i] && str2[i] &&
			(unsigned char)str1[i] == (unsigned char)str2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/**
 * str_cmp - compare if is equal 2 strings
 * @str1: string1
 * @str2: string2
 * Return: 0 success; else pointer
 */
int     str_cmp(const char *str1, const char *str2)
{
		return (str_ncmp(str1, str2, (size_t)-1));
}
