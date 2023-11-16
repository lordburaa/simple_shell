#include "main.h"
/**
 * read_file - reads command from the arguemtn file
 * @file: file containning commands
 * @argv: arugments passed
 * Rreturn: -1  or 0
 */
void read_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		error_file(argv, count);
		exit(127);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		treat_file(line, count, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * treat_file - parse commands and handle
 * @line: form the file
 * * @count: error counter
 * @fp: file discriptor
 * @argv: commands line argumets
 */
void treat_file(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = parse_cmd(line);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_bul_for_file(cmd, line, fp);
	else if (check_builtin(cmd) == 0)
	{
		stat = handle_bultin(cmd, stat);
		free(cmd);
	}
	else
	{
		stat = check_cmd(cmd, line, count, argv);
		free(cmd);
	}
}
/**
 * exit_bul_for_file - exit statsu handler for file input
 * @line: line from a file
 * @cmd: parsed command
 * @fd: file diescriptor
 */
void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int status;
	int i = 0;

	if (cmd[i] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
			perror("Illegal numbr");
	}
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
