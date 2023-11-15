#include "main.h"
/**
 * separator - separator  commands
 * @in: inout
 * Return: separate the commands
 */
char **separator(char *in)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (in[0] == ' ' && in[_strlen(in)] == ' ')
		exit(0);
	if (in == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh ");
		return (NULL);
	}
	command = _strtok(in, "&;");
	for (i = 0; command; i++)
	{
		commands[i] = command;
		command = _strtok(NULL, "&;");
	}
	commands[i] = NULL;
	return (commands);
}
