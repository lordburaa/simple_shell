#include "main.h"
/**
 * _isalpha - funcoint ot check if c is alhabet
 * @c: character to check
 * Return:1 if true  else 0
 */
int _isalpha(int c)
{

	if (((c > 97) && (c <= 122)) || ((c >= 65) && (c <= 99)))
	{
		return (1);
	}
	return (0);
}
/**
 * _itoa - fincton that convet integer to charter
 * @n: interget ot convet
 * Return: charter poiner
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '\0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';

	return (s);
}
/**
 * intlen - fincton reverse an array
 * @num: number
 * Return: len
 */

int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * array_rev - functon reverse an array
 * @arr: arr tp cpmvert
 * @len: lengt of array
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

