#include "main.h"
/**
 * create_envi - create an arry of environment varbles
 * @envi: array to store environment variables
 */
void create_envi(char **envi)
{
	int k;

	for (k = 0; environ[k]; k++)
		envi[k] = _strdup(environ[k]);
	envi[k] = NULL;
}
/**
 * free_env - frees the memory of the created environment varibales aray
 * @envi: aray of environmet  variables
 */
void free_env(char **envi)
{
	int k;

	for (k = 0; envi[k]; k++)
	{
		free(envi[k]);
	}
}
