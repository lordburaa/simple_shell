#include "main.h"

int check_builtin(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{NULL, NULL}
	};
