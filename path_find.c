#include "main.h"
/**
 * path_cmd - search in $PATH  for executable command
 * @cmd: parsed input
 * Return: 0 if succes or 1 on failure
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}
/**
 * _getenv - get environment
 * @name: environmetn name
 * Return: ponter
 */
char *_getenv(char *name)
{
	size_t len_name, len_value;
	char *value;
	int i, j, k;

	len_name = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], len_name) == 0)
		{
			len_value = _strlen(environ[i]) - len_name;
			value = malloc(sizeof(char) * len_value);
			if (!value)
			{
				free(value);
				perror("unable to allocate");
				return (NULL);
			}
			j = 0;
			for (k = len_name + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';
			return (value);
		}
	}
	return (NULL);
}
/**
 * build - build command
 * @token: exutable command
 * @value:direcotry ocontaining command
 * Return: parsed full path of command or nul lif failed
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}
	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, " ");
	cmd = _strcat(cmd, token);

	return (cmd);
}
