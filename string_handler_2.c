#include "main.h"
/**
 * _strcpy - string copy
 * @dest: destination
 * @stc:  string to be checked
 * Return: pointer to the destinatoin
 */
char *_strcpy(char *dest, char *stc)
{
	int i = 0;

	while (stc[i])
	{
		dest[i]  = stc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - string compared
 * @ptr: string to chekc
 * @str: string ot check
 * Return: 1  not success else  0
 */
int _strcmp(char *ptr, char *str)
{
	int cmp = 0, i, len1, len2;

	len1 = _strlen(ptr);
	len2 = _strlen(str);

	if (ptr == NULL || str == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; ptr[i]; i++)
	{
		if (ptr[i] != str[i])
		{
			cmp = ptr[i] - str[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _strncmp -  compare  the string until the the given byte
 * @ptr: string to be chkcd
 * @str: string to be ckecd
 * @n: size
 * Return: 0 if succes else 1
 */
int _strncmp(const char *ptr, const char *str, size_t n)
{
	size_t i;

	if (ptr == NULL)
		return (-1);
	for (i = 0; i < n && str[i]; i++)
	{
		if (ptr[i] != str[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - string copy to new memory
 * @str: string to be checed
 * Return: pointer
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}
	return (str2);
}
/**
 * _strcat - function that concatinates two string
 * @dest: first string
 * @src: second string
 * Return: first string + second string
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
