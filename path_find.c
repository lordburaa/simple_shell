#include "main.h"
/**
 * path_find - search in $PATH  for executable command
 * @cmd: parsed input
 * Return: 0 if succes or 1 on failure
 */
int path_cmd(char **cmd)
{
	char *path, 8vlaue, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL);
	{
		cmd_paht = build(*cmd, value);
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
