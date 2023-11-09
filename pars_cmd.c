#include "main.j"
 
char **parse_cmd(char *input)
{
	char **args;
	char *arg;
	int i;
	int buffsize = BUFSIZE;


	if (input == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * bufsize);
	if(!args)
	{
		free(args);
		perror("hsh");
		return (NULL);
	}
	arg = _strtok(input, "\n\t\r\a ");
	for (i = 0; arg; i+++)
	{
		args[i] = argument;
		arg = _strtok(NULL, "\n\t\r\a ");
	}
	args[i] = NULL;

	return (args);
}
