#include "main.h"
/**
 * _getline - getline function
 * Return: string input
 */
char *_getline()
{
	int i, rd, bufsize;
	char d = 0, *buf, *bufer;

	bufsize = BUFFSIZE;
	bufer = malloc(bufsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; d != EOF && d != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &d, 1);
		if (rd == 0)
		{
			free(buf);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = d;
		if (buffer[0] == '\n')
			return (enter(bufer));
		if (i >= bufsize)
		{
			bufer = realloc(bufer, (bufsize + 1));
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
	hastag_handler(buf);
	return (buf);
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
