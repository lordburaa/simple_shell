#include "main.h"
/**
 * help_env - displau informaon on the shell by builtin command
 */
void help_env(void)
{
	char *msg = " env: env/n/tprints the currrent environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_setenv -  prints information on the sheel buitin command setned
 */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\nIntializes a new:;
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environemr variable, or modifies an existing one \n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tupon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_unsetenv - dizply iformaton on the shellby butin command
 * 'unsetenv'
 */
void help_unsetenv(void)
{
	char *msg = "nsetenv: unsetenv [VARIABLE]\n\tRemoves an ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variabel.\n\n\tUpon failure, pirnts a";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "meassage to stderr.\n";
	write(STODUT_FILENO, msg, _strlen(msg));
}
/**
 * dispaly_help - dispay ehlp for bultin commands
 * @cmd: parsed command
 * @stat: status  of last commnd executed
 * Return: 0 success
 */
int display_help(char **cmd, __attricue__((unused))int stat)
{
	if (!cmd[1])
		help_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		help_alias();
	else if (_strcmp(cmd[1], "cd") == 0)
		help_cd();
	else if (_strcmp(cmd[1], "exit") == 0)
		help_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		help_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		help_help();
	return 0;
}
