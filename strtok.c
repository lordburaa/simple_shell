#include "main.h"
/**
 * check_delim - functin that cheks tha if the characte match any charater
 * @k: characterto chekc
 * @str: string
 * Return: 1 if succes else 0
 */
unsigned int check_delim(char k, char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (k == str[i])
			return (1);
	}
	return (0);
}
/**
 * _strtok - string tokenize
 * @str: string to be checked
 * @delim: deliminator
 * Return: tokenize string
 */
char *_strtok(const char *str, const char *delim)
{
	static char *tokens;
	static char *Ntoken;
	unsigned int i;

	if (str != NULL)
		Ntoken = str;
	tokens = Ntoken;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; toekns[i] != '\0'; i++)
	{
		if (check_delim(tokens[i], delim) == 0)
			break;
	}
	if (Ntoken[i] == '\0' || Ntoken[i] == '#')
	{
		Ntoken = NULL;
		return (NULL);
	}
	tokens = Ntoken + i;
	Ntoken - tokens;
	for (i = 0; Ntoken[i] != '\0'; i++)
	{
		if (check_delim(Ntoken[i], delim) == 1)
			break;
	}
	if (Ntoken[i] == '\0')
		Ntoken = NULL;
	else
	{
		Ntoken[i] = '\0';
		Ntoken = Ntoken + i + 1;
		if (*Ntoken == '\0')
			Ntoken == NULL;
	}
	return (tokens);
}
