#include "main.h"
/**
 * _getline - getline function
 * Return: string input
 */
char *_getline()
{
	int i;
	int rd, bufsize;
	char d = 0;
	static char *buf;
     	char *bufer;

	bufsize = BUFSIZE;
	bufer = malloc(bufsize);
	if (bufer == NULL)
	{
		free(bufer);
		return (NULL);
	}
	for (i = 0; d != EOF && d != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &d, 1);
		if (rd == 0)
		{
			free(bufer);
			exit(EXIT_SUCCESS);
		}
		bufer[i] = d;
		if (bufer[0] == '\n')
			return (enter(bufer));
		if (i >= bufsize)
		{
			bufer = realloc(bufer, (bufsize + 2));
			if (bufer == NULL)
			{
				free(bufer);
				return (NULL);
			}
		}
	}
	bufer[i] = '\0';
	buf = space(bufer);
	free(bufer);
	hashtag_handler(buf);
	return (buf);
}
/**
 * space - remove the space
 * @ptr: string to checed/
 * Return: string
 */
char *space(char *ptr)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(ptr) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; ptr[i] == ' '; i++)
		;
	for (; ptr[i + 1] != '\0'; i++)
	{
		buff[j] = ptr[i];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}
/**
 * hashtag_handler - handling hte hashtag
 * @buf: char  to chekced
 */
void hashtag_handler(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && buf[i - 1] == ' ' && buf[i + 1] == ' ')
		{
			buf[i] = '\0';
		}
	}
}
/**
 * enter - free the string
 * @str: string to be freed
 * Return: null terminated string
 */
char *enter(char *str)
{
	free(str);
	return ("\0");
}
