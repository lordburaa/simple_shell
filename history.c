#include "main.h"
/**
 * history - write file with user input
 * @in: user input
 * Return: 0 success -1 failure
 */
int history(char *in)
{
	char *filename = ".simmple_shell_hisotry";
	ssize_t fd, w;
	int leng = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (in)
	{
		while (in[leng])
			leng++;
		w = write(fd, in, leng);
		if (w < 0)
			return (-1);
	}
	return (1);
}
