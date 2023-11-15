#include "main.h"
/**
 * main - main funcitn
 * @argc: number of argumetns
 * @argv: vecotr
 * * Return: 0 sucess
 */

int main(int argc, char **argv)
{
	char *input;
	int cond = 1;

	while (cond)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		intput = _getline();
		if (input[0] == '\0')
			continue;
		commands = separator(input);
		for (i = 0; command[i] != NULL; i++)
		{
			cmd = parse_cmd(commnads[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, input, argv, count, stat);
			}
			else if (check_builtin(cmd) == 0)
			{
				stat = handle_bultin(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = check_cmd(cmd, input, count, argv);
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&stat);
	}
	return (stat);
}
