#include "shell.h"
#define BUFF_SIZE 32

/**
 * fun_read_line - print a line of f_d
 * @f_d: file descriptor
 * @line: line of text
 * Return: execution of read_line: 1 if success
 */
int fun_read_line(const int f_d, char **line)
{
	int			reader;
	char		*tmp;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[4864];

	if (f_d < 0 || BUFF_SIZE <= 0 || line == NULL || read(f_d, buffer, 0) < 0)
		return (-1);
	while ((reader = read(f_d, buffer, BUFF_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (!str[f_d])
			str[f_d] = _strdup(buffer);
		else
		{
			tmp = f_strjoin(str[f_d], buffer);
			free(str[f_d]);
			str[f_d] = tmp;
		}
		if (_strchr(str[f_d], '\n'))
			break;
	}
	if (str[f_d] == NULL && reader == 0)
		return (-1);
	return (f_read_line(str, line, f_d));
}

/**
 * new_read_line - read a line from f_d
 * @str: grip of documment
 * @f_d: file descriptor
 * @line: line of text
 * Return: 1 if success
 */
int	new_read_line(char **str, char **line, int f_d)
{
	char	*tmp;
	int		count;

	count = 0;
	while (str[f_d][count] != '\0' && str[f_d][count] != '\n')
		count++;
	*line = f_strsub(str[f_d], 0, count);
	if (str[f_d][count] == '\n')
	{
		tmp = _strdup(&str[f_d][count + 1]);
		free(str[f_d]);
		str[f_d] = tmp;
		if (str[f_d][0] == '\0')
			f_strdel(&str[f_d]);
	}
	else
		f_strdel(&str[f_d]);
	return (1);
}

/**
 * fun_help - get help command
 * @commands: array of strings to execute
 * Return: 0 if is positive (1 is true min.); -1 if is error
 */
int fun_help(char **commands)
{

	int f_d, i = 1, result = -1;
	char *line = NULL;

	while (commands[i])
	{
		f_d = open(commands[i], O_RDONLY);
		if (f_d != -1)
		{
			result = 0;
			while (new_read_line(f_d, &line) == 1)
			{
				puts(line);
				free(line);
			}
			close(f_d);
		}
		i++;
	}

	return (result);
}
