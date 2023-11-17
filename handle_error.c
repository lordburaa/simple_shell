#include "main.h"
/**
 * print_error - print error message
 * @in:  INPUT RECIEVED FORM USER
 * @counter: count loop
 * @argv: arguments before programm start
 */
void print_error(char *in, int counter, char **argv)
{
	char *er;

	PRINT(argv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(in);
	PRINT(": command not found\n");
}
/**
 * _perror - prints custom error
 * @argv: argumets before program starts
 * @i: error count
 * @cmd: array of parsed command strings
 */
void _perror(char **argv, int i, char **cmd)
{
	char *er = _itoa(i);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}
/**
 * error_file - prints custom error
 * @argv: argumets before the programm satarts
 * @i: error count
 */
void error_file(char **argv, int i)
{
	char *er = _itoa(i);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(er);
}
