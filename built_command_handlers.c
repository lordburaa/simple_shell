#include "main.h"
/**
 * check_builtin - cheks if parse commadn in buit- jin
 * @cmd: parsed command to be check
 * Return: 0 success   -1 fail
 */
int check_builtin(char **cmd)
{
	int i = 0;
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{NULL, NULL}
	};

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (_sttrcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * exit_bul - exit status for buitl in commands
 * @cmd: array of parse command strings
 * @input: input recieved from user (to be freed)
 * @argv: arguments before program starts
 * @c: shell executoin ecount
 * @stat: exit status
 */
void exit_bul(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_perror(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1])
				if (status == 2)
				{
					_perror(arv, c, cmd);
					free(input);
					free(cmd);
					xit(status);
				}
			free(input);
			free(cmd);
			exit(status);
		}
	}
}
/**
 * handle_bultin - handles predefined built in commands
 * @cmd: aray of parsed command string
 * @st: status of last execution
 * Return: -1 failure 0 sucess
 */
int handle_bultin(char **cmd, int st)
{
	buitin built_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"echo", echo_bul},
		{"help", display_help},
		{"history", history_dis},
		{NULL, NULL}
	};
	int  i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmmd[0], (built_in + i)->command) == 0)
		{
			return ((buit_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}
