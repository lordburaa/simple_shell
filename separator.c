#include "main.h"

char **separator(char *input)
{
	char **commands;
	char *command;
	int i;
	int bufsize = BUFSIZE;

	if (input == NULL)
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
