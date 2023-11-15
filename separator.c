#include "main.h"
/**
 * separator - spearate th command recived form stdin by ; and &
 * @in:  input from the stdin
 * Return: paprsed string to be used as command
 */
char **separator(char *in)
{
	char **commands;
	char *command;
	int i;
	int bufsize = BUFSIZE;

	if (in == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * bufsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	command = _strtok(input, ";&");
	for (i = 0; command; i++)
	{
		cmds[i] = cmd;
		cmd = _strtok(NULL, ";&");
	}
	cmds[i] = NULL;
	return (cmds);
}
