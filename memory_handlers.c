#include "main.h"
/**
 * _realloc - reallloates memrou block using malloc and free
 * @ptr: ponter
 * @o_size: old size of the pointer
 * @n_size: new size of the pointer
 * Return: pointer to ralocated memory
 */
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	void *result;

	if (n_size == old_size)
		return (ptr);
	if (n_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = mallo(n_size);

	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', n_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, o_size);
		free(ptr);
	}
	return (result);
}
/**
 * free_all -free memory allocated
 * @cmd: array pointer
 * @input: char poiner
 * Return: void
 */
void free_all(char **cmd, char *input)
{
	free(cmd);
	free(input);
	cmd = NULL;
	input = NULL;
}
/**
 * _calloc - allocate memory of an aray using malloc
 * @size: size
 * Return: void potinter
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size ; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
/**
 * fill_an_array - fill an array by costant byte
 * @a: void pointer
 * @el: int
 * @len: lentght ofr int
 * Return: void pointer
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _memcpy - copy bytes of memory from source ot destination
 * @dest: d estinamton ponter
 * @src: source pointer
 * @n: size to be copied
 * Return: poitr ot destinamtion
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
