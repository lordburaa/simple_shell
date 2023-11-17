#include "main.h"
/**
 * main - main funcitn
 * @argc: number of argumetns
 * @argv: vecotr
 * * Return: 0 sucess
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *input, **cmd, **commands;
	int cond = 1;
	int count = 0;
	int status, i;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handle);
	while (cond)
	{
		if (isatty(STDIN_FILENO))
			propt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		commands = separator(input);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = parse_cmd(commands[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, input, argv, count, status);
			}
			else if (check_builtin(cmd) == 0)
			{
				status = handle_bultin(cmd, status);
				free(cmd);
				continue;
			}
			else
				status = check_cmd(cmd, input, count, argv);
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&status);
	}
	return (status);
}
