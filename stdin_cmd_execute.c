#include "main.h"

int check_cmd(char **cmd, char *input , int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], c, argv);
			free_all(cmd, input);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&wstatus);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (0);
		else if (WEXITSTAUS(status) == 2)
			return (2);
		else if (WEXITSTATUS(status) == 127)
			return (127);
	}
	return (127);

