#include "main.h"
/**
 * check_cmd - check cmd
 * @cmd: command
 * @in: input
 * @i: int
 * @argv: argument
 * Return: number
 */
int check_cmd(char **cmd, char *in, int i, char **argv)
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
			print_error(cmd[0], i, argv);
			free_all(cmd, in);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (0);
		else if (WEXITSTATUS(status) == 2)
			return (2);
		else if (WEXITSTATUS(status) == 127)
			return (127);
	}
	return (127);
}
/**
 * signal_to_handle - configure c not to terminate our shell
 * @signal:  incoming signal
 */
void signal_to_handle(int signal)
{
	if (signal == SIGINT)
	{
		PRINT("\n$ ");
	}
}
