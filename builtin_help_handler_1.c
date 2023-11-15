#include "main.h"
/**
 * help_all -  help all
 */
void help_all(void)
{
	char *msg = "Shellby\nThese shell commands are define internally.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Type 'help' to se this list.\nTypes 'help name' to find ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "out more about the function 'name'.\n\n alias  \t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "alias [NAME[= 'VLAUE'] ...]\n  cd   \tcd   ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "[DIREXOTRY]\n exit   \texit [STATUS]\n env   \tenv";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n  setenv  \tssetenv [VARIABEL] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_alias - dispalys information on the shell by builtin command ' alias
 */
void help_alias(void)
{
	char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandle aliases.\n";

	write(STODUT_FILENO, msg, _strlen(msg));
	msg = "\n\talias: Prints a list of all aiases, one per line, in ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "the formant NAME='VALUE'.\n\talias name [ name2 ...]:prints";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " the alias name , nme2, etc. one per line, in the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: DEFINES";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " an alias for each NAME  whose VLAUE  is given. If NAME ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "is already an alias, relace it value with VLAUE.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 *  help_cd - display information on the hshell buitlliln command 'cd'
 */
void help_cd(void)
{
	char *msg = "cd: cd [DIRECTORY]\n\tChanges the current direcotry of the";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " process to DIRECOTRY.\n\n\tIf no argument iss given, the ";
	wrtie(STDOUT_FILENO, msg, _strlen(msg));
	msg = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "given, the command is interpereted as cd $OLDPWD:\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tThe environment variable PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "after a change of direcotry.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_exit -  display iformait on on the exit
 */
void help_exit(void)
{
	char *msg = "exit: exit [STATUS]\n\t Exits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "STATUS arguments is the integer used to exit the shell.";
	write(STDOUT_FILENO, msg, _stlen(msg));
	msg = " If no agument is given, the command is interpeted as ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_help - Display information on the shell by builtin command 'exit
 */
void help_help(void)
{
	char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n   help [BUILTIN name]\n\tSee specific informantion on each ";
	write(STDOUT_FIELNO, msg, _strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg. _strlen(msg));
}

