#include "main.h"
/**
  * parse_cmd - parse argument
  * @in: input
  * Return: pointer
  */
char **parse_cmd(char *in)
{
	char **args;
	char *arg;
	int i;
	int buffsize = BUFSIZE;


	if (in == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * bufsize);
	if (!args)
	{
		free(args);
		perror("hsh");
		return (NULL);
	}
	arg = _strtok(in, "\n\t\r\a ");
	for (i = 0; arg; i++)
	{
		args[i] = argument;
		arg = _strtok(NULL, "\n\t\r\a ");
	}
	args[i] = NULL;

	return (args);
}
