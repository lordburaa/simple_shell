#include "main.h"
/**
 * change_dir - change direcotry
 * @cmd: parsed command
 * @st: status of last command executed
 * Return: 0 if failed
 */
int change_dir(char **cmd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
	{
		value = chdir(getenv("HOME"));
	}
	else if (_strcmp(cmd[1], "-") == 0)
		value = chdir(getenv("OLDPWD"));
	else
		value = chdir(cmd[1]);
	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * dis_env - display environmet vaiable4
 * @cmd: parsed command
 * @st: status last command
 * Return: Akways 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * echo_bul - execute echo cases
 * @st: statsu of last command execute
 * @cmd: parded command
 * Return: Akways 1 or execute norman echo
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_int(st);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_echo(cmd));
	return (1);
}
/**
 * history_dis - display hostpry user input on simple_shell
 * @c: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 failure
 */
int history_dis(__attribute__((unused))char **c, __attribute((unused))int st)
{
	char *filename = " simple shell history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

