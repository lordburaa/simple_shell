#include "main.h"
/**
 * _putchar -  print a char
 * * @c: char to check
 * Return: string
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - functio that print string
 * @str: pointer to string
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 * _strncpy - funcotin that copues a string
 * @dest: destrination string
 * @src:source string
 * @n: number of characterto be copid
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
/**
 * _strlen - functon that counts the lengt hof string
 * @s: string ot in put
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i  = 0; s[i] != '\0'; i++)
	{
	continue;
	}
	return (i);
}
/**
 * _atoi - functin to convert string ot integer
 * @s: strig input
 * Return: convet integer
 */
int _atoi(char *s)
{
	int i = 0;
	int j = 1;
	int k;
	unsigned int l = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			return (2);
		}
		k = s[i] - '0';

		if (l > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			l = l * 10 + k;

		i++;
	}
	l *= j;
	return (l);
}
