#include "main.h"
void print_number(unsigned int num);
/**
 * print_number_int - prints integers using _ putchar fucntoin
 * @num: integer to pointer
 */
void print_number_int(int num)
{
	usigned int x = num;

	if (num < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);
	_putchar(x % 10 + '0');
}
/**
 * print_number - prints unsigned integer using putchar functoin
 * @num: unsigned integer to printed
 */
void print_number(unsigned int num)
{
	unsigned int x = num;

	if ((x / 10) > 0)
		print_number(x / 10);
	_putchar(x % 10 + '0');
}
/**
 * print_echo - execcutes built - int echo fucntion
 * @cmd: parsed command
 * Return: 0 upon succes  - failure
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/cho", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
